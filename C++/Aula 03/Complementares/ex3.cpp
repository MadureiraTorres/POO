#include <iostream>
#include <stdexcept>
using namespace std;

// ──────────────────────────────────────────────
// Nó da lista
// ──────────────────────────────────────────────
struct No{
    int valor;
    No *proximo;

    No(int v) : valor(v), proximo(nullptr){}

    ~No(){}
};

class Lista{
    private:
        No *cabeca;


        void liberarTudo(){
            No *atual = cabeca;
            while (atual != nullptr){
                No *prox = atual->proximo;
                delete atual;
                atual = prox;
            }
            cabeca = nullptr;
        }

    public:
        Lista() : cabeca(nullptr){
            cout << "[+] Lista criada (vazia)\n";
        }

        Lista(const Lista &outra) : cabeca(nullptr){
            No *src = outra.cabeca;
            No **dst = &cabeca;

            while (src != nullptr){
                *dst = new No(src->valor);
                dst = &((*dst)->proximo);
                src = src->proximo;
            }
        cout << "[+] Lista copiada (deep copy)\n";
        }

        Lista &operator=(Lista outra){
            swap(cabeca, outra.cabeca);
            cout << "[=] Lista atribuída (swap)\n";
            return *this;
        }

        ~Lista(){
            liberarTudo();
            cout << "[-] Lista destruída\n";
        }

        void inserir(int valor){
            No *novo = new No(valor);
            novo->proximo = cabeca;
            cabeca = novo;
        }

        void inserirFim(int valor){
            No *novo = new No(valor);
            if (!cabeca){
                cabeca = novo;
                return;
            }
        
            No *cur = cabeca;
            while (cur->proximo)
                cur = cur->proximo;
            cur->proximo = novo;
        }

        void exibir() const{
            No *cur = cabeca;
            cout << "  Lista: ";
            while (cur){
                cout << cur->valor;
            
                if (cur->proximo)
                    cout << " -> ";
                cur = cur->proximo;
            }
        cout << " -> NULL\n";
        }

        bool vazia() const { return cabeca == nullptr; }
};

int main(){
    cout << "=== Lista original ===\n";
    Lista l1;
    l1.inserirFim(10);
    l1.inserirFim(20);
    l1.inserirFim(30);
    l1.exibir();

    cout << "\n=== Cópia (deep copy) ===\n";
    Lista l2(l1);
    l2.inserirFim(40);
    cout << "l1 após modificar l2:\n";
    l1.exibir();
    cout << "l2:\n";
    l2.exibir();

    cout << "\n=== Teste de escopo — destruição automática ===\n";{
        Lista l3;
        for (int i = 1; i <= 5; ++i)
            l3.inserirFim(i * 100);
        l3.exibir();
        cout << "  [Saindo do escopo — l3 será destruída]\n";
    }

    cout << "\n=== Aviso sobre stack overflow ===\n";
    cout << "  Se o destrutor do No fosse recursivo (delete proximo),\n"
              << "  uma lista com ~100.000 nós causaria stack overflow.\n"
              << "  Esta implementação usa loop iterativo no destrutor da Lista.\n";

    cout << "\n[Saindo do main]\n";
    return 0;
}