#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Processo;

class Gerenciador{
    private:
        vector<Processo *> ativos;

        Gerenciador() = default;

    public:
        static Gerenciador &instancia(){
            static Gerenciador g;
            return g;
        }

        void registrar(Processo *p){
            ativos.push_back(p);
        }

        void remover(Processo *p){
            ativos.erase(
                remove(ativos.begin(), ativos.end(), p),
                ativos.end());
        }

        void listar_ativos() const;

        size_t quantidade() const { return ativos.size(); }
};


class Processo{
    private:
        string nome;
        int pid;
        static int proximoPid;

    public:
        Processo(const string &nome) : nome(nome), pid(proximoPid++){
            Gerenciador::instancia().registrar(this);
            cout << "[+] Processo criado:   " << pid << " (" << nome << ")\n";
        }

        ~Processo(){
            Gerenciador::instancia().remover(this);
            cout << "[-] Processo destruído: " << pid << " (" << nome << ")\n";
        }

        Processo(const Processo &) = delete;
        Processo &operator=(const Processo &) = delete;

        int getPid() const { return pid; }
        string getNome() const { return nome; }
};

int Processo::proximoPid = 100;

void Gerenciador::listar_ativos() const{
    cout << "\n  ┌─ Processos ativos (" << ativos.size() << ") ─────────\n";
    if (ativos.empty()){
        cout << "  │  (nenhum)\n";
    }
    else{
        for (const auto *p : ativos)
            cout << "  │  PID " << p->getPid()
                      << "  —  " << p->getNome() << "\n";
    }
    cout << "  └──────────────────────────────\n\n";
}

int main(){
    auto &G = Gerenciador::instancia();

    cout << "=== Escopo externo ===\n";
    Processo p1("init");
    Processo p2("systemd");

    G.listar_ativos();

    {
        cout << "  === Escopo interno A ===\n";
        Processo p3("nginx");
        Processo p4("postgres");

        G.listar_ativos();

        {
            cout << "    === Escopo interno B ===\n";
            Processo p5("worker-1");
            Processo p6("worker-2");

            G.listar_ativos();

            cout << "    [Saindo do escopo B]\n";
        }

        G.listar_ativos();
        cout << "  [Saindo do escopo A]\n";
    }

    G.listar_ativos();
    cout << "[Saindo do main — p1 e p2 serão destruídos]\n";

    return 0;
}