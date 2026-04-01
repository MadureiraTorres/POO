#ifndef JOGADOR_H //tinha funcionado sem, mas é melhor colocar
#define JOGADOR_H

#include <iostream>
#include <string>

using namespace std;

//deixar o código modular para a próxima entrega (ok)
//colocar o using namespace std para facilitar as chamadas de string etc (ok)

class Jogador{
    private:
        string nome;
        string classe;
        int vidaMax; //upa com vitalidade
        int vidaAtual;
        int staminaMax; //upa com resistência ou fortitude, não sei ainda
        int staminaAtual;
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


    public:
        Jogador(string nome, string classe, int nivel, int almas, int vitalidade, 
                int conhecimento, int fortitude, int forca, int destreza, int resistencia, 
                int inteligencia, int fe, int vidaMax, int staminaMax){
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
            this->vidaMax = vidaMax;            //LEMBRAR QUE NAS PRÓXIMAS ETAPAS DO PROJETO, A VIDA MAX VAI DEPENDER DE ATRIBUTOS (HERANÇA)
            this->vidaAtual = vidaMax;
            this->staminaMax = staminaMax;
            this->staminaAtual = staminaMax;
        }

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

        void exibirStatus(){
            cout << "Nome: " << this->nome << endl;
            cout << "Classe: " << this->classe << endl;
            cout << "Nivel: " << this->nivel << endl;
            cout << "Vida: " << this->vidaAtual << endl;
            cout << "Stamina: " << this->stamina << endl; 
            cout << "Almas: " << this->almas << endl;
            cout << "Vitalidade: " << this->vitalidade << endl;
            cout << "Conhecimento: " << this->conhecimento << endl;
            cout << "Fortitude: " << this->fortitude << endl;
            cout << "Forca: " << this->forca << endl;
            cout << "Destreza: " << this->destreza << endl;
            cout << "Resistencia: " << this->resistencia << endl;
            cout << "Inteligencia: " << this->inteligencia << endl;
            cout << "Fe: " << this->fe << endl;
        }

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

        bool estaVivo(int vida){
            return vida > 0;
        }

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

        int receberDano(int dano){
            this->vidaAtual -= dano;
            if(this->vidaAtual < 0){
                this->vidaAtual = 0;
            }
            return this->vidaAtual;
        }

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

        int curar(int cura){
            this->vidaAtual += cura;
            
            if(this->vidaAtual > this->vidaMax){
                this->vidaAtual = this->vidaMax; 
            }

            return this->vidaAtual;
        } //se curar e passar do hp máximo setar como hp máximo (ok)
};

#endif
