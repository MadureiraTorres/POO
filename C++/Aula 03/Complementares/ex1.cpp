#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
criar classe livro, com atributos titulo, autor e ano
implementar construtores que aceitem diferentes combinações de parâmetros com e sem ano
usar destrutor para exibir mensagem de desalocação
criar um vetor/lista de livros e observar a ordem de destruição
*/

class Livro {
    private:
        string titulo;
        string autor;
        int ano;
 
    public:
        
        Livro() : titulo("Sem título"), autor("Desconhecido"), ano(0){
            cout << "[+] Livro criado (padrão): \"" << titulo << "\"\n";
        }
 
        Livro(const std::string& titulo, const std::string& autor) : titulo(titulo), autor(autor), ano(0){
            cout << "[+] Livro criado (sem ano): \"" << this->titulo << "\"\n";
        }
 
    
        Livro(const std::string& titulo, const std::string& autor, int ano) : titulo(titulo), autor(autor), ano(ano){
            cout << "[+] Livro criado (completo): \"" << this->titulo << "\" (" << this->ano << ")\n";
        }
 
        ~Livro(){
            cout << "[-] Livro destruído: \"" << titulo << "\"\n";
        }
 
        void exibir() const{
            cout << "  Título: " << titulo << " | Autor: " << autor << " | Ano: " << (ano > 0 ? std::to_string(ano) : "N/A") << endl;
        }
};
 
int main() {
    Livro l1;
    Livro l2("Dom Quixote", "Cervantes");
    Livro l3("1984", "George Orwell", 1949);
 
    l1.exibir();
    l2.exibir();
    l3.exibir();
 
    cout << "\n=== Criando vetor de livros ===\n";
    {
        vector<Livro> biblioteca;
        biblioteca.emplace_back("O Senhor dos Anéis", "Tolkien", 1954);
        biblioteca.emplace_back("Harry Potter",       "J.K. Rowling", 1997);
        biblioteca.emplace_back("Clean Code",         "Robert Martin", 2008);
 
        cout << "\nLivros na biblioteca:\n";
        for (const auto& livro : biblioteca)
            livro.exibir();
 
        cout << "\n[Saindo do escopo da biblioteca — destruição na ordem reversa]\n";
    }
 
    cout << "\n[Saindo do main — l3, l2, l1 são destruídos]\n";
    
    return 0;
}