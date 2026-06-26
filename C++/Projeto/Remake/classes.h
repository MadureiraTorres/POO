#ifndef CLASSES_H
#define CLASSES_H

#include "jogador.h"
using namespace std;

// ── Guerreiro ─────────────────────────────────────────────────────────────────
class Guerreiro : public Jogador {
    private:
        string raca;

    public:
        Guerreiro(const string &nm, const string &rc)
            : Jogador(nm, 1, 200), raca(rc) {
            setStatus(10, 4);   // força alta, dex baixa
        }

        virtual ~Guerreiro(){
            cout << "[destrutor] Guerreiro " << getNome() << " destruído." << endl;
        }

        string getRaca() const { return raca; }

        void exibirStatus() override {
            cout << "Classe: Guerreiro | Raça: " << raca << endl;
            Jogador::exibirStatus();
        }

        // dano físico baseado em Força
        void atacar(Jogador &alvo) override {
            int dano = getForca() * 3;
            cout << getNome() << " (Guerreiro/" << raca << ") ataca "
                 << alvo.getNome() << " causando " << dano << " de dano!" << endl;
            alvo.receberDano(dano);
        }
};

// ── Mago ──────────────────────────────────────────────────────────────────────
class Mago : public Jogador {
    private:
        string raca;
        int    mana;
        int    manaMax;

    public:
        Mago(const string &nm, const string &rc)
            : Jogador(nm, 1, 80), raca(rc), mana(150), manaMax(150) {
            setStatus(2, 12);   // dex alta, força baixa
        }

        virtual ~Mago(){
            cout << "[destrutor] Mago " << getNome() << " destruído." << endl;
        }

        string getRaca()    const { return raca; }
        int    getMana()    const { return mana; }
        int    getManaMax() const { return manaMax; }

        void exibirStatus() override {
            cout << "Classe: Mago | Raça: " << raca << endl;
            Jogador::exibirStatus();
            cout << "Mana: " << mana << "/" << manaMax << endl;
        }

        // dano mágico baseado em Dex; consome mana
        void atacar(Jogador &alvo) override {
            int custo = 20;
            if(mana < custo){
                cout << getNome() << " não tem mana suficiente!" << endl;
                return;
            }
            int dano = getDex() * 5;
            mana -= custo;
            cout << getNome() << " (Mago/" << raca << ") lança magia em "
                 << alvo.getNome() << " causando " << dano << " de dano! (mana: "
                 << mana << ")" << endl;
            alvo.receberDano(dano);
        }
};

// ── Ladrão ────────────────────────────────────────────────────────────────────
class Ladrao : public Jogador {
    private:
        string raca;
        bool   furtivo;

    public:
        Ladrao(const string &nm, const string &rc)
            : Jogador(nm, 1, 120), raca(rc), furtivo(false) {
            setStatus(5, 10);   // dex alta, força média
        }

        virtual ~Ladrao(){
            cout << "[destrutor] Ladrão " << getNome() << " destruído." << endl;
        }

        string getRaca()    const { return raca; }
        bool   isFurtivo()  const { return furtivo; }
        void   setFurtivo(bool f) { furtivo = f; }

        void exibirStatus() override {
            cout << "Classe: Ladrão | Raça: " << raca << endl;
            Jogador::exibirStatus();
            cout << "Furtivo: " << (furtivo ? "Sim" : "Não") << endl;
        }

        // golpe furtivo dobra o dano se estiver em modo furtivo
        void atacar(Jogador &alvo) override {
            int dano = getDex() * 2;
            if(furtivo){
                dano *= 2;
                cout << getNome() << " (Ladrão/" << raca << ") aplica GOLPE FURTIVO em "
                     << alvo.getNome() << " causando " << dano << " de dano!" << endl;
                furtivo = false;
            } else {
                cout << getNome() << " (Ladrão/" << raca << ") ataca "
                     << alvo.getNome() << " causando " << dano << " de dano!" << endl;
            }
            alvo.receberDano(dano);
        }
};

#endif