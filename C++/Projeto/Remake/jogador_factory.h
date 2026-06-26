#ifndef JOGADOR_FACTORY_H
#define JOGADOR_FACTORY_H

#include "classes.h"
using namespace std;

class JogadorFactory {
    public:
        // raças válidas: "humano", "elfo", "anão", "orc"
        static Guerreiro* criarGuerreiro(const string &nome, const string &raca){
            validarRaca(raca);
            Guerreiro* g = new Guerreiro(nome, raca);
            aplicarBonusRaca(g, raca);
            return g;
        }

        static Mago* criarMago(const string &nome, const string &raca){
            validarRaca(raca);
            Mago* m = new Mago(nome, raca);
            aplicarBonusRaca(m, raca);
            return m;
        }

        static Ladrao* criarLadrao(const string &nome, const string &raca){
            validarRaca(raca);
            Ladrao* l = new Ladrao(nome, raca);
            aplicarBonusRaca(l, raca);
            return l;
        }

    private:
        static void validarRaca(const string &raca){
            if(raca != "humano" && raca != "elfo" && raca != "anão" && raca != "orc")
                throw invalid_argument("Raça desconhecida: " + raca);
        }

        // bônus de raça aplicados sobre os stats base da classe
        static void aplicarBonusRaca(Jogador* j, const string &raca){
            if(raca == "humano"){
                // humanos: +1 em tudo (versáteis)
                j->setStatus(j->getForca() + 1, j->getDex() + 1);
            } else if(raca == "elfo"){
                // elfos: +3 dex
                j->setStatus(j->getForca(), j->getDex() + 3);
            } else if(raca == "anão"){
                // anões: +3 forca, +50 hp
                j->setStatus(j->getForca() + 3, j->getDex());
                j->setHP(j->getHPMax() + 50);
            } else if(raca == "orc"){
                // orcs: +5 forca, -2 dex
                j->setStatus(j->getForca() + 5, j->getDex() - 2);
            }
        }
};

#endif