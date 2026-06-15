//refazendo toda classe seguindo o  que foi pedido ao final dos slides
#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string>
using namespace std;

class Jogador{
    private:
        string nome;
        int nivel;
        int hpAtual;
        int hpMax;
        int exp;

    public:
        //construtor
        Jogador(string nm, int lv, int hp){
            setNome(nm);
            setNivel(lv);
            setHP(hp);
        }

        //getters (acesso)
        string getNome() const{
            return nome;
        }

        int getNivel() const{
            return nivel;
        }

        int getHPMax() const{
            return hpMax;
        }

        int getHPAtual() const{
            return hpAtual;
        }

        int getXP() const{
            return exp;
        }
        
        //setters (validadores)
        void setNome(string nm){
            nome = nm;
        }

        void setHP(int vida){
            hpMax = vida;
            hpAtual = hpMax;
        }

        void setNivel(int lv){
            if(lv > 0){
                nivel = lv;
            } else{
                throw invalid_argument("Nível deve ser positivo");
            }
        }

        void setXP(int xp){
            exp = xp;
        }

        //métodos
        void exibirStatus(){
            string vivo = estaVivo() ? "Vivo" : "Morto";
            

            cout << "Nome: " << getNome() << endl;
            cout << "Nível: " << getNivel() << endl;
            cout << "HP: " << getHPAtual() << "/" << getHPMax() << endl;
            cout << vivo << endl;
        }

        bool estaVivo() const{
            if(hpAtual > 0){
                return true;
            }
            return false;
        }

        void receberDano(int dano){
            if(estaVivo() == true){ //já não está com validação?
                hpAtual -= dano;
                
                if(hpAtual < 0){
                    hpAtual = 0;
                }
            }
        }

        void curar(int cura){
            if(estaVivo() == true){ //como aplicar validação aqui?
                hpAtual += cura;

                if(hpAtual > hpMax){
                    hpAtual = hpMax;
                }
            }
        }

        void experiencia(int quant){
            //???????????
        }

        void subirNivel(){
            nivel++;
        }
    };

#endif