//refazendo toda classe seguindo o  que foi pedido ao final dos slides
#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Jogador{
    private:
        string nome;
        int nivel;
        int hpAtual;
        int hpMax;
        int exp;
        int forca;
        int dex;
        int lvuppoints;

    public:
        //construtor
        Jogador(const string &nm, int lv, int hp){
            setNome(nm);
            setNivel(lv);
            setHP(hp);
            setStatus(2, 2);
            setXP(0);
            setLVUP(0);
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
        
        int getForca() const{
            return forca;
        }

        int getDex() const{
            return dex;
        }

        int getLVUP() const{
            return lvuppoints;
        }

        //setters (validadores)
        void setNome(const string &nm){
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

        void setLVUP(int a){
            lvuppoints = a;
        }

        void setStatus(int a, int b){
            forca = a;
            dex = b;
        }

        //métodos
        void exibirStatus(){
            string vivo = estaVivo() ? "Vivo" : "Morto";
            

            cout << "Nome: " << getNome() << endl;
            cout << "Nível: " << getNivel() << endl;
            cout << "HP: " << getHPAtual() << "/" << getHPMax() << endl;
            cout << "Experiência: " << getXP() << endl;
            cout << "Força: " << getForca() <<endl;
            cout << "Destreza: " << getDex() << endl;
            cout << vivo << endl;
        }

        bool estaVivo() const{
            if(hpAtual > 0){
                return true;
            }
            return false;
        }

        void receberDano(int dano){
            if(dano <= 0){
                return;
            }
            if(estaVivo()){
                hpAtual -= dano;
                if(hpAtual < 0){
                    hpAtual = 0;
                }
            }
        }

        void curar(int cura){
            if(cura <= 0){
                return;
            }
            if(estaVivo()){
                hpAtual += cura;
                if(hpAtual > hpMax){
                    hpAtual = hpMax;
                }
            }
        }
    
        void experiencia(int quant){
            if(quant <= 0){
                return;
            }

            setXP(getXP() + quant);
            int aux = nivel * 100;

            if(getXP() >= aux){
                setLVUP(getLVUP() + 1);
            }
        }

        //fiz isso de exemplo, pois vamos mudar pra um esquema melhor
        void subirNivel(){
            if(lvuppoints > 0){
                nivel++;
                setStatus(getForca() + 2, getDex() + 2);
                hpMax += 100;
                hpAtual = hpMax;
                setLVUP(getLVUP() - 1);

                cout << "Level Up!" << endl;
            }
        }
        
    };

#endif 
