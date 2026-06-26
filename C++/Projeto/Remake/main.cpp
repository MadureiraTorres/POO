#include "jogador.h"
#include <vector>

// ----- subclasses -----

class Guerreiro : public Jogador {
    public:
        Guerreiro(const string &nm, int lv, int hp)
            : Jogador(nm, lv, hp) {}

        virtual ~Guerreiro() {
            cout << "[destrutor] Guerreiro " << getNome() << " destruído." << endl;
        }

        // ataque físico: dano baseado em Força
        void atacar(Jogador &alvo) override {
            int dano = getForca() * 3;
            cout << getNome() << " (Guerreiro) ataca " << alvo.getNome()
                 << " causando " << dano << " de dano!" << endl;
            alvo.receberDano(dano);
        }
};

class Mago : public Jogador {
    public:
        Mago(const string &nm, int lv, int hp)
            : Jogador(nm, lv, hp) {}

        virtual ~Mago() {
            cout << "[destrutor] Mago " << getNome() << " destruído." << endl;
        }

        // ataque mágico: dano baseado em Destreza
        void atacar(Jogador &alvo) override {
            int dano = getDex() * 5;
            cout << getNome() << " (Mago) lança magia em " << alvo.getNome()
                 << " causando " << dano << " de dano!" << endl;
            alvo.receberDano(dano);
        }
};

class Arqueiro : public Jogador {
    public:
        Arqueiro(const string &nm, int lv, int hp)
            : Jogador(nm, lv, hp) {}

        virtual ~Arqueiro() {
            cout << "[destrutor] Arqueiro " << getNome() << " destruído." << endl;
        }

        // ataque à distância: dano misto
        void atacar(Jogador &alvo) override {
            int dano = (getForca() + getDex()) * 2;
            cout << getNome() << " (Arqueiro) atira em " << alvo.getNome()
                 << " causando " << dano << " de dano!" << endl;
            alvo.receberDano(dano);
        }
};

// ----- main -----

int main() {

    Guerreiro inimigo("Goblin", 1, 200);

    vector<Jogador*> grupo;
    grupo.push_back(new Guerreiro("Arthur",  2, 150));
    grupo.push_back(new Mago    ("Merlin",   3, 80 ));
    grupo.push_back(new Arqueiro("Legolas",  2, 100));

    cout << "=== Status inicial do inimigo ===" << endl;
    inimigo.exibirStatus();

    cout << "\n=== Grupo ataca (polimorfismo) ===" << endl;

    for (Jogador* j : grupo) {
        j->atacar(inimigo);
    }

    cout << "\n=== Status do inimigo após ataques ===" << endl;
    inimigo.exibirStatus();

    cout << "\n=== Status do grupo ===" << endl;
    for (Jogador* j : grupo) {
        j->exibirStatus();
        cout << endl;
    }

    cout << "=== Liberando memória ===" << endl;
    for (Jogador* j : grupo) {
        delete j;
    }
    grupo.clear();

    return 0;
}