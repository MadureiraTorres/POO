#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Livro{
    protected:
        int chave;
        string titulo;
        string autor;
        int ano;

    private:
        static int proximaChave;

    public:
        Livro(const string& titulo, const string& autor, int ano)
            : titulo(titulo), autor(autor), ano(ano){
            this->chave = proximaChave++;
            cout << "[+] Livro criado (base): \"" << this->titulo << "\" (chave " << this->chave << ")\n";
        }

        virtual ~Livro(){
            cout << "[-] Livro destruído: \"" << titulo << "\" (chave " << chave << ")\n";
        }

        virtual void exibir() const{
            cout << "  Chave : " << chave  << "\n";
            cout << "  Título: " << titulo << "\n";
            cout << "  Autor : " << autor  << "\n";
            cout << "  Ano   : " << (ano > 0 ? to_string(ano) : "N/A") << "\n";
        }
};

int Livro::proximaChave = 1;

class LivroFisico : public Livro{
    private:
        int numeroPaginas;

    public:
        LivroFisico(const string& titulo, const string& autor, int ano, int numeroPaginas)
            : Livro(titulo, autor, ano), numeroPaginas(numeroPaginas){
            cout << "[+] LivroFisico criado: \"" << this->titulo << "\" (" << numeroPaginas << " págs.)\n";
        }

        ~LivroFisico(){
            cout << "[-] LivroFisico destruído: \"" << titulo << "\"\n";
        }

        void exibir() const override {
            cout << "  ---- Livro Físico ----\n";
            Livro::exibir();
            cout << "  Págs. : " << numeroPaginas << "\n";
        }
};

class LivroDigital : public Livro{
    private:
        float tamanhoArquivo;
        string formato;

    public:
        LivroDigital(const string& titulo, const string& autor, int ano,
                    float tamanhoArquivo, const string& formato)
            : Livro(titulo, autor, ano), tamanhoArquivo(tamanhoArquivo), formato(formato){
            cout << "[+] LivroDigital criado: \"" << this->titulo << "\" (" << formato << ", " << tamanhoArquivo << " MB)\n";
        }

        ~LivroDigital(){
            cout << "[-] LivroDigital destruído: \"" << titulo << "\"\n";
        }

        void exibir() const override{
            cout << "  ---- Livro Digital ----\n";
            Livro::exibir();
            cout << "  Formato: " << formato << "\n";
            cout << "  Tamanho: " << tamanhoArquivo << " MB\n";
        }
};

class LivroAcademicoDigital : public LivroDigital{
    private:
        string area;
        string instituicao;

    public:
        LivroAcademicoDigital(const string& titulo, const string& autor, int ano,
                            float tamanhoArquivo, const string& formato,
                            const string& area, const string& instituicao)
            : LivroDigital(titulo, autor, ano, tamanhoArquivo, formato),
            area(area), instituicao(instituicao){
            cout << "[+] LivroAcademicoDigital criado: \"" << this->titulo << "\" | " << area << " - " << instituicao << "\n";
        }

        ~LivroAcademicoDigital(){
            cout << "[-] LivroAcademicoDigital destruído: \"" << titulo << "\"\n";
        }

        void exibir() const override{
            cout << "  ---- Livro Acadêmico Digital ----\n";
            LivroDigital::exibir();
            cout << "  Área  : " << area        << "\n";
            cout << "  Inst. : " << instituicao << "\n";
        }
};

int main(){
    cout << "=== Criando objetos ===\n\n";

    vector<Livro*> colecao;
    colecao.push_back(new Livro("Dom Casmurro", "Machado de Assis", 1899));
    colecao.push_back(new LivroFisico("O Senhor dos Anéis", "J.R.R. Tolkien", 1954, 1178));
    colecao.push_back(new LivroDigital("Clean Code", "Robert C. Martin", 2008, 2.5f, "PDF"));
    colecao.push_back(new LivroAcademicoDigital(
        "Introdução à Computação", "Ana Silva", 2020,
        1.8f, "EPUB", "Ciência da Computação", "UTFPR"
    ));

    cout << "\n=== Exibindo coleção ===\n";
    for (const auto& livro : colecao){
        cout << "\n";
        livro->exibir();
    }

    cout << "\n=== Destruindo objetos (ordem reversa) ===\n\n";
    for (int i = colecao.size() - 1; i >= 0; i--){
        delete colecao[i];
        cout << "\n";
    }
    colecao.clear();

    return 0;
}