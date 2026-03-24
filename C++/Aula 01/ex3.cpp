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
        float tamanhoTela;

};

class estaLigada{

};

class volume{

};

class estaMutada{
    
};

class canal{

};

class canalAnterior{

};

int main(){
    return 0;
}