#include <iostream>
#include <string>

//vou copiar os atributos do dark souls 1, que é o melhor rpg de todos kkkkkkkkk

class Jogador{
    public:
        std::string nome;
        std::string classe;
        int vida; //upa com vitalidade
        int stamina; //upa com resistência ou fortitude, não sei ainda
        int nivel; //nivel aumenta conforme upamos os atributos abaixo
        int almas; //moeda de compra e que também serve para upar os atributos 
        int vitalidade; //quant de hp, quando eu abrir o jogo de novo eu vejo o que de sub-atributo upa com ele
        int conhecimento; //quant de espaços para alocar magias, quando eu abrir o jogo de novo eu vejo o que de sub-atributo upa com ele
        int fortitude; //quant de peso que o jogador pode carregar, responsavel tbm pelo poise, e a stamina é aqui ou na resistencia
        int forca; //quant de dano causado com armas que usam esse atributo, serve como nota de corte pra usar armas de força
        int destreza; //quant de dano causado com armas que usam esse atributo, serve como nota de corte pra usar armas de dex
        int resistencia; //não me lembro se é aqui a stamina ou na fortitude
        int inteligencia; //atributo para usar sorceries/sortilégios, nota de corte pra magias
        int fe; //atributo pra usar milagres (e acho que tem uma piromância que tem dano base de fé)

        //implementar depois os sub-atributos

        Jogador(std::string nome, std::string classe, int nivel, int almas, int vitalidade, 
            int conhecimento, int fortitude, int forca, int destreza, int resistencia, int inteligencia, int fe){
            this->nome = nome;
            this->classe = classe;
            this->nivel = nivel;
            this->almas = almas;
            this->vitalidade = vitalidade;
            this->conhecimento = conhecimento;
            this->fortitude = fortitude;
            this->forca = forca;
            this->destreza = destreza;
            this->resistencia = resistencia;
            this->inteligencia = inteligencia;
            this->fe = fe;
        }

        void exibirStatus(){
            std::cout << "Nome: " << this->nome << std::endl;
            std::cout << "Classe: " << this->classe << std::endl;
            std::cout << "Nivel: " << this->nivel << std::endl;
            std::cout << "Vida: " << this->vida << std::endl;
            std::cout << "Stamina: " << this->stamina << std::endl;
            std::cout << "Almas: " << this->almas << std::endl;
            std::cout << "Vitalidade: " << this->vitalidade << std::endl;
            std::cout << "Conhecimento: " << this->conhecimento << std::endl;
            std::cout << "Fortitude: " << this->fortitude << std::endl;
            std::cout << "Forca: " << this->forca << std::endl;
            std::cout << "Destreza: " << this->destreza << std::endl;
            std::cout << "Resistencia: " << this->resistencia << std::endl;
            std::cout << "Inteligencia: " << this->inteligencia << std::endl;
            std::cout << "Fe: " << this->fe << std::endl;
        }

        bool estaVivo(int vida){
            return vida > 0;
        }

        int receberDano(int dano){ //perguntar pro prof se eu posso fazer isso
            this->vida -= dano;
            if(this->vida < 0){
                this->vida = 0;
            }
            return this->vida;
        }

        int curar(int cura){ //perguntar pro prof se eu posso fazer isso
            this->vida += cura;
            return this->vida;
        }
};

int main(){
    return 0;
}