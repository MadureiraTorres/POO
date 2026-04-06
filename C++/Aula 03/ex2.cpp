#include <iostream>
using namespace std;

/*
criar uma classe matriz, que aloca dinamicamente um array 2d de inteiros no construtor
recebendo linhas e colunas como parâmetros; o destrutor deve liberar a memória alocada;
implementar o construtor de cópia para que duas matrizes não compartilhem o mesmo 
bloco de memória; demonstrar na main que modificar a cópia não afeta o original.
*/

class Matriz{
    private:
        int** data;
        int linhas;
        int colunas;

    public:
        Matriz(int l, int c) : linhas(l), colunas(c){
            data = new int*[linhas];
            for (int i = 0; i < linhas; i++){
                data[i] = new int[colunas];
            }
        }

        Matriz(const Matriz& other) : linhas(other.linhas), colunas(other.colunas){
            data = new int*[linhas];
            for (int i = 0; i < linhas; i++){
                data[i] = new int[colunas];
                for (int j = 0; j < colunas; j++){
                    data[i][j] = other.data[i][j];
                }
            }
        }

        ~Matriz(){
            for (int i = 0; i < linhas; i++){
                delete[] data[i];
            }
            
            delete[] data;
        }

        void preencher(int valor){
            for (int i = 0; i < linhas; i++){
                for (int j = 0; j < colunas; j++){
                    data[i][j] = valor;
                }
            }
        }

        void imprimir(){
            for (int i = 0; i < linhas; i++){
                for (int j = 0; j < colunas; j++){
                    cout << data[i][j] << " ";
                }
                cout << endl;
            }
        }
};


int main(){
    Matriz m1(2, 3);
    m1.preencher(5); 
  
    cout << "Matriz Original:" << endl;
    m1.imprimir();

    Matriz m2 = m1;
    m2.preencher(10);

    cout << "Matriz Modificada:" << endl;
    m2.imprimir();
    
    cout << "Matriz Original após modificação da cópia:" << endl;
    m1.imprimir();
    
    return 0;
}