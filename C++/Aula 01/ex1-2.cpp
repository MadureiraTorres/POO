#include <iostream>
#include <string>
#include <utility>

class ImagemDigital {
    private:
        int largura;
        int altura;
        std::string nome_arquivo;

    public:
        ImagemDigital(int largura, int altura, std::string nome_arquivo) {
            this->largura       = largura;
            this->altura        = altura;
            this->nome_arquivo  = nome_arquivo;
        }

        void redimensionar(int nova_largura, int nova_altura) {
            this->largura = nova_largura;
            this->altura  = nova_altura;
        }

        std::pair<int, int> get_dimensoes() {
            return std::make_pair(this->largura, this->altura);
        }

        std::string get_nome_arquivo() {
            return this->nome_arquivo;
        }

        int get_largura()  { return this->largura; }
        int get_altura()   { return this->altura;  }
};

int main() {
    ImagemDigital imagem(1920, 1080, "imagem.jpg");

    std::cout << "Largura: "        << imagem.get_largura()       << "\n";
    std::cout << "Altura: "         << imagem.get_altura()        << "\n";
    std::cout << "Nome do arquivo: "<< imagem.get_nome_arquivo()  << "\n";

    imagem.redimensionar(800, 600);

    std::cout << "Nova largura: "   << imagem.get_largura()  << "\n";
    std::cout << "Nova altura: "    << imagem.get_altura()   << "\n";

    std::pair<int, int> dimensoes = imagem.get_dimensoes();
    std::cout << "Dimensões: ("     << dimensoes.first << ", " << dimensoes.second << ")\n";

    std::string nome_arquivo = imagem.get_nome_arquivo();
    std::cout << "Nome do arquivo: "<< nome_arquivo << "\n";

    return 0;
}
