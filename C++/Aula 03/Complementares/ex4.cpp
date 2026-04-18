#include <iostream>
#include <new>     
#include <cstring> 
using namespace std;

class Produto{
    private:
        int id;
        double preco;
        char nome[32]; 

    public:
        Produto() : id(0), preco(0.0){
            memset(nome, 0, sizeof(nome));
            cout << "  [Produto()  construído id=" << id << "]\n";
        }

        Produto(int id, double preco, const char *nome) : id(id), preco(preco){
            strncpy(this->nome, nome, sizeof(this->nome) - 1);
            this->nome[sizeof(this->nome) - 1] = '\0';
            cout << "  [Produto construído: " << this->nome << "]\n";
        }

        ~Produto(){
            cout << "  [~Produto destruído: " << nome << "]\n";
        }

        void exibir() const{
            cout << "    Produto #" << id
                    << " | " << nome
                    << " | R$ " << preco << "\n";
        }
};

template <typename T, size_t N>

class PoolMemoria{
    private:
        alignas(T) char bloco[sizeof(T) * N]; 
        bool ocupado[N];                      
        size_t tamanho;                  

    public:
        PoolMemoria() : tamanho(0){
            memset(ocupado, 0, sizeof(ocupado));
            cout << "[+] Pool criado ("
                    << N << " slots de " << sizeof(T) << " bytes = "
                    << sizeof(T) * N << " bytes)\n";
        }

        template <typename... Args>
        T *construir(Args &&...args){
            for (size_t i = 0; i < N; ++i){
                if (!ocupado[i]){
                    void *ptr = bloco + i * sizeof(T);
                    T *obj = new (ptr) T(forward<Args>(args)...);
                    ocupado[i] = true;
                    ++tamanho;
                    return obj;
                }
            }
            throw bad_alloc(); 
        }

        void destruir(T *obj){
            char *p = reinterpret_cast<char *>(obj);
            ptrdiff_t offset = p - bloco;
            size_t idx = offset / sizeof(T);

            if (idx < N && ocupado[idx]){
                obj->~T(); 
                ocupado[idx] = false;
                --tamanho;
            }
        }

        ~PoolMemoria(){
            cout << "[-] Pool sendo destruído — chamando destrutor de "
                    << tamanho << " objeto(s) vivo(s)...\n";
            for (size_t i = 0; i < N; ++i){
                if (ocupado[i]){
                    T *obj = reinterpret_cast<T *>(bloco + i * sizeof(T));
                    obj->~T(); // destrutor explícito
                    ocupado[i] = false;
                }
            }
            cout << "[-] Bloco do pool liberado\n";
        }

        size_t getTamanho() const { return tamanho; }
};

int main(){
    cout << "=== Criando pool de 4 Produtos ===\n";{
        PoolMemoria<Produto, 4> pool;

        cout << "\n-- Construindo objetos no pool --\n";
        Produto *p1 = pool.construir(1, 29.90, "Caneta");
        Produto *p2 = pool.construir(2, 149.90, "Teclado");
        Produto *p3 = pool.construir(3, 59.90, "Mouse");

        cout << "\n-- Objetos no pool --\n";
        p1->exibir();
        p2->exibir();
        p3->exibir();

        cout << "\n-- Destruindo p2 manualmente --\n";
        pool.destruir(p2);
        // p2 agora é inválido — slot liberado

        cout << "\n-- Reutilizando slot liberado --\n";
        Produto *p4 = pool.construir(4, 999.00, "Monitor");
        p4->exibir();

        cout << "\n[Saindo do escopo — pool.~PoolMemoria() chamado]\n";
    }

    cout << "\n[Fim do main]\n";
    return 0;
}