/**
 * @file inimigo.cpp
 * @brief Implementação dos inimigos e estratégias de IA.
 */
#include "inimigo.h"

namespace RPG {

// ── IAgressiva ────────────────────────────────────────────────────────────────

std::string IAgressiva::getNome() const { return "Agressiva"; }

void IAgressiva::agir(Entidade &self, Entidade &alvo) {
    int dano = self.getNivel() * 15 + 20;
    std::cout << self.getNome() << " ataca furiosamente causando "
              << dano << " de dano!" << std::endl;
    alvo.receberDano(dano);
}

// ── IACautelosa ───────────────────────────────────────────────────────────────

std::string IACautelosa::getNome() const { return "Cautelosa"; }

void IACautelosa::agir(Entidade &self, Entidade &alvo) {
    if (rand() % 10 < 6) {
        int dano = self.getNivel() * 10 + 15;
        std::cout << self.getNome() << " ataca cautelosamente causando "
                  << dano << " de dano!" << std::endl;
        alvo.receberDano(dano);
    } else {
        std::cout << self.getNome() << " recua e aguarda uma abertura..." << std::endl;
    }
}

// ── IABoss ────────────────────────────────────────────────────────────────────

std::string IABoss::getNome() const { return "Boss"; }

void IABoss::agir(Entidade &self, Entidade &alvo) {
    turno++;
    if (turno % 3 == 0) {
        // ataque especial a cada 3 turnos
        int dano = self.getNivel() * 30 + 60;
        std::cout << "⚔  " << self.getNome()
                  << " desencadeia ATAQUE ESPECIAL causando "
                  << dano << " de dano!" << std::endl;
        alvo.receberDano(dano);
    } else {
        int dano = self.getNivel() * 18 + 30;
        std::cout << self.getNome() << " golpeia com força causando "
                  << dano << " de dano!" << std::endl;
        alvo.receberDano(dano);
    }
}

// ── Inimigo base ──────────────────────────────────────────────────────────────

Inimigo::Inimigo(const std::string &nm, int hp, int lv,
                 int exp, int almas, ComportamentoIA* ia)
    : Entidade(nm, hp, lv),
      expRecompensa(exp), almasRecompensa(almas), ia(ia) {}

Inimigo::~Inimigo() { delete ia; }

int Inimigo::getExpRecompensa()   const { return expRecompensa; }
int Inimigo::getAlmasRecompensa() const { return almasRecompensa; }

void Inimigo::atacar(Entidade &alvo) {
    if (!estaVivo() || !ia) return;
    ia->agir(*this, alvo);
}

void Inimigo::exibirStatus() const {
    std::cout << "[ INIMIGO ] " << nome
              << " | Nível " << nivel
              << " | HP " << hpAtual << "/" << hpMax
              << " | IA: " << ia->getNome() << std::endl;
}

// ── Inimigos concretos ────────────────────────────────────────────────────────

HollowSoldier::HollowSoldier()
    : Inimigo("Soldado Oco", 180, 1, 200, 150, new IACautelosa()) {}

BlackKnight::BlackKnight()
    : Inimigo("Cavaleiro Negro", 450, 5, 800, 600, new IAgressiva()) {}

PinwheelBoss::PinwheelBoss()
    : Inimigo("Catavento (Boss)", 1200, 8, 2000, 1500, new IABoss()) {}

GargoyleBoss::GargoyleBoss()
    : Inimigo("Gárgula da Torre Bell (Boss)", 1800, 10, 3500, 2500, new IABoss()) {}

OrnsSteinBoss::OrnsSteinBoss()
    : Inimigo("Ornstein, o Caçador de Dragões (Boss)", 3500, 20, 20000, 15000, new IABoss()) {}

} // namespace RPG