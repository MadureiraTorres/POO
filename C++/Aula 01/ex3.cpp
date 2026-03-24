#include <iostream>
#include <string>

/*
implementar classes:
marca, modelo, estaLigada, volume, estaMutada, canal, canalAnterior

implementar metodos:
ligar(), desligar(), aumentarVolume(), diminuirVolume(), mutar(), desmutar(), proximoCanal(), voltarCanal(), acessarCanal(numeroCanal)
*/

class marca{
    //atributos
    public:
        std::string nome;
        std::string paisOrigem;

        //construtor
        marca(std::string nome, std::string paisOrigem){
            this->nome = nome;
            this->paisOrigem = paisOrigem;
        }
    
};

class modelo{
    public:
        int ano;
        int codigo;
        float tamanhoTela;

        modelo(int ano, int codigo, float tamanhoTela){
            this->ano = ano;
            this->codigo = codigo;
            this->tamanhoTela = tamanhoTela;
        }
};

class estaLigada{
    public:
        bool ligada;

        estaLigada(bool ligada){
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

class volume{
    public:
        int nivel;

        volume(int nivel){
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

class estaMutada{
    public:
        bool mutada;

        estaMutada(bool mutada){
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

class canal{   
    public:
        float numero;

        canal(float numero){
            if(numero > 0){
                this->numero = numero;
            } else {
                this->numero = 1;
            }
        }

        float proximoCanal(){
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

class canalAnterior{
    public:
        float numeroAnterior;

        canalAnterior(float numeroAnterior){
            if(numeroAnterior > 0){
                this->numeroAnterior = numeroAnterior;
            } else {
                this->numeroAnterior = 1;
            }
        }

        float voltarCanal(){
            if(this->numeroAnterior > 1){
                this->numeroAnterior--;
            }
            return this->numeroAnterior;
        }

};

int main(){
    marca marca1("Sony", "Japão");
    modelo modelo1(2020, 12345, 55.0);
    estaLigada estaLigada1(true);
    volume volume1(50);
    estaMutada estaMutada1(false);
    canal canal1(5.0);
    canalAnterior canalAnterior1(4.0);


    return 0;
}