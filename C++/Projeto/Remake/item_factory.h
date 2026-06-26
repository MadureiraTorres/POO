#ifndef ITEM_FACTORY_H
#define ITEM_FACTORY_H

#include "itens.h"
#include <stdexcept>
using namespace std;

class ItemFactory {
    public:
        // tipos de arma: "espada", "cajado", "arco", "adaga"
        static Arma* criarArma(const string &tipo){
            if(tipo == "espada")  return new Arma("Espada de Ferro",   150, 35);
            if(tipo == "cajado")  return new Arma("Cajado Arcano",     200, 50);
            if(tipo == "arco")    return new Arma("Arco Longo",        120, 28);
            if(tipo == "adaga")   return new Arma("Adaga Envenenada",  100, 20);
            throw invalid_argument("Arma desconhecida: " + tipo);
        }

        // tipos de armadura: "pesada", "media", "leve", "robe"
        static Armadura* criarArmadura(const string &tipo){
            if(tipo == "pesada")  return new Armadura("Armadura de Placas", 300, 50);
            if(tipo == "media")   return new Armadura("Cota de Malha",      200, 30);
            if(tipo == "leve")    return new Armadura("Couro Reforçado",    100, 15);
            if(tipo == "robe")    return new Armadura("Robe Mágico",        150, 10);
            throw invalid_argument("Armadura desconhecida: " + tipo);
        }

        // tipos de poção: "pequena", "media", "grande", "elixir"
        static Pocao* criarPocao(const string &tipo){
            if(tipo == "pequena") return new Pocao("Poção Pequena",  30,  50);
            if(tipo == "media")   return new Pocao("Poção Média",    60, 150);
            if(tipo == "grande")  return new Pocao("Poção Grande",  100, 300);
            if(tipo == "elixir")  return new Pocao("Elixir Divino", 500, 999);
            throw invalid_argument("Poção desconhecida: " + tipo);
        }
};

#endif