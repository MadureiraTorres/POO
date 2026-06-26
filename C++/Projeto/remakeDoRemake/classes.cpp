/**
 * @file classes.cpp
 * @brief Implementação das classes de personagem jogáveis.
 */
#include "classes.h"

namespace RPG {

// ── Cavaleiro ─────────────────────────────────────────────────────────────────

Cavaleiro::Cavaleiro(const std::string &nm, Raca* raca)
    : Personagem(nm, 1, 220, 13, 11, 9, 9, 11, raca)
{
    adicionarHabilidade(new AtaquePesado());
    adicionarHabilidade(new IronFlesh());
}

std::string Cavaleiro::getClasse() const { return "Cavaleiro"; }

void Cavaleiro::levelUp() {
    Personagem::levelUp();
    forca += 1;         // cavaleiros ganham força extra no level up
    aumentarHPMax(25);  // e HP adicional
}

// ── Piromante ─────────────────────────────────────────────────────────────────

Piromante::Piromante(const std::string &nm, Raca* raca)
    : Personagem(nm, 1, 120, 10, 9, 12, 8, 10, raca),
      mana(80), manaMax(80)
{
    adicionarHabilidade(new Piromancia());
    adicionarHabilidade(new AlmaTorrencial());
}

int         Piromante::getMana()    const { return mana; }
int         Piromante::getManaMax() const { return manaMax; }
std::string Piromante::getClasse()  const { return "Piromante"; }

void Piromante::levelUp() {
    Personagem::levelUp();
    inteligencia += 1;
    manaMax      += 20;
    mana          = manaMax;
}

void Piromante::exibirStatus() const {
    Personagem::exibirStatus();
    std::cout << "│ Mana: " << mana << "/" << manaMax << std::endl;
}

// ── Ladino ────────────────────────────────────────────────────────────────────

Ladino::Ladino(const std::string &nm, Raca* raca)
    : Personagem(nm, 1, 140, 9, 15, 10, 9, 9, raca), furtivo(false)
{
    adicionarHabilidade(new PunhaladaCostas());
}

bool        Ladino::isFurtivo()   const { return furtivo; }
std::string Ladino::getClasse()   const { return "Ladino"; }

void Ladino::ativarFurtivo() {
    furtivo = true;
    std::cout << getNome() << " entra em modo furtivo!" << std::endl;
}

void Ladino::levelUp() {
    Personagem::levelUp();
    dex += 1;
}

void Ladino::atacar(Entidade &alvo) {
    if (furtivo) {
        // golpe furtivo: dobra o dano
        Arma* arma = inventario.getArmaEquipada();
        int dano = arma ? arma->calcularDano(forca, dex) * 2 : dex * 4;
        std::cout << getNome() << " emerge das sombras — GOLPE FURTIVO em "
                  << alvo.getNome() << " causando " << dano << " de dano!" << std::endl;
        alvo.receberDano(dano);
        furtivo = false;
    } else {
        Personagem::atacar(alvo);
    }
}

// ── Clérigo ───────────────────────────────────────────────────────────────────

Clerigo::Clerigo(const std::string &nm, Raca* raca)
    : Personagem(nm, 1, 160, 11, 8, 9, 14, 10, raca)
{
    adicionarHabilidade(new MiraculoCura());
    adicionarHabilidade(new AtaquePesado());
    estusCargasMax += 2;    // clérigos têm mais estus
    estusCargas     = estusCargasMax;
}

std::string Clerigo::getClasse() const { return "Clérigo"; }

void Clerigo::levelUp() {
    Personagem::levelUp();
    fe               += 1;
    estusRecuperacao += 10;
}

} // namespace RPG