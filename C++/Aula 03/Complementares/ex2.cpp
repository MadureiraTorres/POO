#include <iostream>
using namespace std;

class Sensor{
    private:
        int id;
        static int contagem;

    public:
        Sensor(int id) : id(id){
            ++contagem;
            cout << "[+] Sensor " << id << " criado.     Instâncias ativas: " << contagem << "\n";
        }

        ~Sensor(){
            cout << "[-] Sensor " << id << " destruído.  Instâncias ativas: " << (contagem - 1) << "\n";
            --contagem;
        }

        static int getContagem() { return contagem; }

        int getId() const { return id; }
};

int Sensor::contagem = 0;

int main(){
    cout << "=== Escopo externo ===\n";
    Sensor s1(1);
    Sensor s2(2);

    {
        cout << "\n  === Escopo interno A ===\n";
        Sensor s3(3);
        Sensor s4(4);

        {
            cout << "\n    === Escopo interno B (mais profundo) ===\n";
            Sensor s5(5);
            cout << "    Sensores ativos agora: " << Sensor::getContagem() << "\n";
            cout << "    [Saindo do escopo B]\n";
        }

        cout << "\n  Sensores ativos depois do escopo B: "
             << Sensor::getContagem() << "\n";
        cout << "  [Saindo do escopo A]\n";
    }

    cout << "\nSensores ativos depois do escopo A: "
         << Sensor::getContagem() << "\n";
    cout << "[Saindo do main — s1 e s2 são destruídos]\n";

    return 0;
}