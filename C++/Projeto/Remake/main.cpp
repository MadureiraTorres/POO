#include "jogador_factory.h"
#include "item_factory.h"
#include <vector>
using namespace std;

int main(){
    // ── JogadorFactory ────────────────────────────────────────────────────────
    cout << "=== Criando jogadores via JogadorFactory ===" << endl;

    vector<Jogador*> grupo;
    grupo.push_back(JogadorFactory::criarGuerreiro("Thorin",  "anão"));
    grupo.push_back(JogadorFactory::criarMago     ("Legolas", "elfo"));
    grupo.push_back(JogadorFactory::criarLadrao   ("Garret",  "humano"));

    for(Jogador* j : grupo){
        j->exibirStatus();
        cout << endl;
    }

    // ── ItemFactory ───────────────────────────────────────────────────────────
    cout << "=== Criando itens via ItemFactory ===" << endl;

    vector<Item*> loja;
    loja.push_back(ItemFactory::criarArma    ("espada"));
    loja.push_back(ItemFactory::criarArma    ("cajado"));
    loja.push_back(ItemFactory::criarArmadura("pesada"));
    loja.push_back(ItemFactory::criarArmadura("robe"));
    loja.push_back(ItemFactory::criarPocao   ("grande"));
    loja.push_back(ItemFactory::criarPocao   ("elixir"));

    for(Item* i : loja){
        i->descrever();
    }

    // ── polimorfismo: grupo ataca inimigo ─────────────────────────────────────
    cout << "\n=== Combate ===" << endl;
    Guerreiro inimigo("Orc Selvagem", "orc");   // criado direto, sem factory
    inimigo.exibirStatus();
    cout << endl;

    // ativa furtivo no ladrão antes de atacar
    static_cast<Ladrao*>(grupo[2])->setFurtivo(true);

    for(Jogador* j : grupo){
        j->atacar(inimigo);
    }

    cout << "\n=== Status do inimigo após combate ===" << endl;
    inimigo.exibirStatus();

    // ── liberação de memória ──────────────────────────────────────────────────
    cout << "\n=== Liberando memória ===" << endl;
    for(Jogador* j : grupo) delete j;
    for(Item*   i : loja)   delete i;

    return 0;
}