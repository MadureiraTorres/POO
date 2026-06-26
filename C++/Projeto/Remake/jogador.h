#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Jogador {
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
        Jogador(const string &nm, int lv, int hp) {
            setNome(nm);
            setNivel(lv);
            setHP(hp);
            setStatus(2, 2);
            setXP(0);
            setLVUP(0);
        }

        // destrutor virtual — obrigatório para evitar vazamento com delete em ponteiro de base
        virtual ~Jogador() {
            cout << "[destrutor] " << nome << " destruído." << endl;
        }

        // getters
        string getNome()  const { return nome; }
        int    getNivel() const { return nivel; }
        int    getHPMax() const { return hpMax; }
        int    getHPAtual() const { return hpAtual; }
        int    getXP()    const { return exp; }
        int    getForca() const { return forca; }
        int    getDex()   const { return dex; }
        int    getLVUP()  const { return lvuppoints; }

        // setters
        void setNome(const string &nm) { nome = nm; }

        void setHP(int vida) {
            hpMax   = vida;
            hpAtual = hpMax;
        }

        void setNivel(int lv) {
            if (lv > 0) nivel = lv;
            else throw invalid_argument("Nível deve ser positivo");
        }

        void setXP(int xp)    { exp = xp; }
        void setLVUP(int a)   { lvuppoints = a; }
        void setStatus(int a, int b) { forca = a; dex = b; }

        // métodos
        virtual void exibirStatus() {
            string vivo = estaVivo() ? "Vivo" : "Morto";
            cout << "Nome: "        << getNome()    << endl;
            cout << "Nível: "       << getNivel()   << endl;
            cout << "HP: "          << getHPAtual() << "/" << getHPMax() << endl;
            cout << "Experiência: " << getXP()      << endl;
            cout << "Força: "       << getForca()   << endl;
            cout << "Destreza: "    << getDex()     << endl;
            cout << vivo            << endl;
        }

        bool estaVivo() const { return hpAtual > 0; }

        void receberDano(int dano) {
            if (dano <= 0 || !estaVivo()) return;
            hpAtual -= dano;
            if (hpAtual < 0) hpAtual = 0;
        }

        void curar(int cura) {
            if (cura <= 0 || !estaVivo()) return;
            hpAtual += cura;
            if (hpAtual > hpMax) hpAtual = hpMax;
        }

        void experiencia(int quant) {
            if (quant <= 0) return;
            setXP(getXP() + quant);
            int limiar = nivel * 100;
            if (getXP() >= limiar) {
                setLVUP(getLVUP() + 1);
                setXP(getXP() - limiar);   // corrigido: desconta o limiar ao invés de acumular
            }
        }

        void subirNivel() {
            if (lvuppoints > 0) {
                nivel++;
                setStatus(getForca() + 2, getDex() + 2);
                hpMax  += 100;
                hpAtual = hpMax;
                setLVUP(getLVUP() - 1);
                cout << "Level Up!" << endl;
            }
        }

        void reviver() {
            if (estaVivo()) throw invalid_argument("Impossível reviver jogador!");
            hpAtual = hpMax;
        }

        // método virtual puro — toda subclasse deve implementar seu próprio atacar()
        virtual void atacar(Jogador &alvo) = 0;
};

#endif