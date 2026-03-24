#include <iostream>
#include <string>

class Jogador{
    public:
        std::string nome;
        std::string classe;
        int nivel;
        int vida;
        int mana;

        Jogador(std::string nome, std::string classe, int nivel, int vida, int mana){
            this->nome = nome;
            this->classe = classe;
            this->nivel = nivel;
            this->vida = vida;
            this->mana = mana;
        }
};

int main(){
    return 0;
}