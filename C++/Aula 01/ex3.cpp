#include <iostream>
#include <string>

/*
implementar classes:
marca, modelo, estaLigada, volume, estaMutada, canal, canalAnterior

implementar metodos:
ligar(), desligar(), aumentarVolume(), diminuirVolume(), mutar(), desmutar(), proximoCanal(), voltarCanal(), acessarCanal(numeroCanal)
*/

class Marca{
    //atributos
    public:
        std::string nome;
        std::string paisOrigem;

        //construtor
        Marca(std::string nome, std::string paisOrigem){
            this->nome = nome;
            this->paisOrigem = paisOrigem;
        }
    
};

class Modelo{
    public:
        int ano;
        int codigo;
        float tamanhoTela;

        Modelo(int ano, int codigo, float tamanhoTela){
            this->ano = ano;
            this->codigo = codigo;
            this->tamanhoTela = tamanhoTela;
        }
};

class EstaLigada{
    public:
        bool ligada;

        EstaLigada(bool ligada){
            this->ligada = ligada;
        }

        bool ligar(){
            this->ligada = true;
            return this->ligada;
        }

        bool desligar(){
            this->ligada = false;
            return this->ligada;
        }
};

class Volume{
    public:
        int nivel;

        Volume(int nivel){
            if(nivel > 0 && nivel <= 100){
                this->nivel = nivel;
            } else {
                this->nivel = 0;
            }
        }

        int aumentarVolume(){
            if(this->nivel < 100){
                this->nivel++;
            }
            return this->nivel;
        }

        int diminuirVolume(){
            if(this->nivel > 0){
                this->nivel--;
            }
            return this->nivel;
        }
};

class EstaMutada{
    public:
        bool mutada;

        EstaMutada(bool mutada){
            this->mutada = mutada;
        }

        bool mutar(){
            this->mutada = true;
            return this->mutada;
        }

        bool desmutar(){
            this->mutada = false;
            return this->mutada;
        }

};

class Canal{   
    public:
        float numero;

        Canal(float numero){
            if(numero > 0){
                this->numero = numero;
            } else {
                this->numero = 1;
            }
        }

        float proximoCanal(float& numeroAnterior){
            numeroAnterior = this->numero; 
            this->numero++;
            return this->numero;
        }

        float acessarCanal(float numeroCanal){
            if(numeroCanal > 0){
                this->numero = numeroCanal;
            }
            return this->numero;
        }
};

class CanalAnterior{
    public:
        float numeroAnterior;

        CanalAnterior(float numeroAnterior){
            this->numeroAnterior = (numeroAnterior > 0) ? numeroAnterior : 1;
        }

        float voltarCanal(float& canalAtual){
            float temp = canalAtual;
            canalAtual = this->numeroAnterior;
            this->numeroAnterior = temp;
            return canalAtual;
        }
};

int main(){
    marca marca1("Sony", "Japão");
    modelo modelo1(2020, 12345, 55.0);
    estaLigada estaLigada1(false);
    volume volume1(50);
    estaMutada estaMutada1(false);
    canal canal1(5);
    canalAnterior canalAnterior1(4);

    estaLigada1.ligar();
    canal1.proximoCanal(canalAnterior1.numeroAnterior); 
    canalAnterior1.voltarCanal(canal1.numero);
    volume1.aumentarVolume();
    estaMutada1.mutar();

    return 0;
}
