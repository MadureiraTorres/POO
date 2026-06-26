#ifndef ITENS_H
#define ITENS_H

#include <iostream>
#include <string>
using namespace std;

// ── classe base abstrata ──────────────────────────────────────────────────────
class Item {
    protected:
        string nome;
        int    valor;

    public:
        Item(const string &nm, int vl) : nome(nm), valor(vl) {}
        virtual ~Item() {}

        string getNome()  const { return nome; }
        int    getValor() const { return valor; }

        virtual void descrever() const = 0;
};

// ── Arma ─────────────────────────────────────────────────────────────────────
class Arma : public Item {
    private:
        int dano;

    public:
        Arma(const string &nm, int vl, int dano) : Item(nm, vl), dano(dano) {}
        virtual ~Arma() {}

        int getDano() const { return dano; }

        void descrever() const override {
            cout << "[Arma] " << nome
                 << " | Dano: " << dano
                 << " | Valor: " << valor << "g" << endl;
        }
};

// ── Armadura ──────────────────────────────────────────────────────────────────
class Armadura : public Item {
    private:
        int defesa;

    public:
        Armadura(const string &nm, int vl, int defesa) : Item(nm, vl), defesa(defesa) {}
        virtual ~Armadura() {}

        int getDefesa() const { return defesa; }

        void descrever() const override {
            cout << "[Armadura] " << nome
                 << " | Defesa: " << defesa
                 << " | Valor: " << valor << "g" << endl;
        }
};

// ── Poção ─────────────────────────────────────────────────────────────────────
class Pocao : public Item {
    private:
        int cura;

    public:
        Pocao(const string &nm, int vl, int cura) : Item(nm, vl), cura(cura) {}
        virtual ~Pocao() {}

        int getCura() const { return cura; }

        void descrever() const override {
            cout << "[Poção] " << nome
                 << " | Cura: " << cura
                 << " | Valor: " << valor << "g" << endl;
        }
};

#endif