#include <iostream>
#include <vector>
#include <algorithm>

class Conjunto {
private:
    std::vector<int> conteudo;

public:
    void adicionar(int valor) {
        if (!pesquisar(valor)) {
            conteudo.push_back(valor);
        }
    }

    void remover(int valor) {
        auto it = std::find(conteudo.begin(), conteudo.end(), valor);
        if (it != conteudo.end()) {
            conteudo.erase(it);
        }
    }

    bool pesquisar(int valor) {
        return std::find(conteudo.begin(), conteudo.end(), valor) != conteudo.end();
    }
};

int main(){
    Conjunto c;
    c.adicionar(5);
    c.adicionar(10);
    c.adicionar(15);

    if (c.pesquisar(10)) {
        std::cout << "10 está no conjunto." << std::endl;
    }

    c.remover(10);
    if (!c.pesquisar(10)) {
        std::cout << "10 não está mais no conjunto." << std::endl;
    }

    return 0;
}