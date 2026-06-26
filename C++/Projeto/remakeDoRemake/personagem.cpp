/**
 * @file personagem.cpp
 * @brief Implementação da classe Personagem.
 */
#include "personagem.h"

namespace RPG {

Personagem::Personagem(const std::string &nm, int lv, int hp,
                       int forca, int dex, int intel, int fe, int vital,
                       Raca* raca)
    : Entidade(nm, hp + raca->bonusHP(), lv),
      forca(forca        + raca->bonusForca()),
      dex(dex            + raca->bonusDex()),
      inteligencia(intel + raca->bonusIntel()),
      fe(fe              + raca->bonusFe()),
      vitalidade(vital   + raca->bonusVital()),
      stamina(100), staminaMax(100),
      exp(0), expProxNivel(lv * 500),
      estusCargasMax(5), estusCargas(5), estusRecuperacao(150),
      raca(raca), inventario(80) {}

Personagem::~Personagem() {
    // Composição: Personagem é dono da Raca e de cada Habilidade
    delete raca;
    for (Habilidade* h : habilidades) delete h;
}

// ── getters ───────────────────────────────────────────────────────────────────

int    Personagem::getForca()        const { return forca; }
int    Personagem::getDex()          const { return dex; }
int    Personagem::getInteligencia() const { return inteligencia; }
int    Personagem::getFe()           const { return fe; }
int    Personagem::getVitalidade()   const { return vitalidade; }
int    Personagem::getStamina()      const { return stamina; }
int    Personagem::getStaminaMax()   const { return staminaMax; }
int    Personagem::getExp()          const { return exp; }
int    Personagem::getExpProxNivel() const { return expProxNivel; }
int    Personagem::getEstusCargas()  const { return estusCargas; }
Raca*  Personagem::getRaca()         const { return raca; }

Inventario& Personagem::getInventario()             { return inventario; }
const Inventario& Personagem::getInventario() const { return inventario; }
const std::vector<Habilidade*>& Personagem::getHabilidades() const { return habilidades; }

// ── stamina ───────────────────────────────────────────────────────────────────

bool Personagem::gastarStamina(int custo) {
    if (stamina < custo) return false;
    stamina -= custo;
    return true;
}

void Personagem::recuperarStamina(int qt) {
    stamina = std::min(staminaMax, stamina + qt);
}

// ── estus ─────────────────────────────────────────────────────────────────────

void Personagem::usarEstus() {
    if (estusCargas <= 0) {
        std::cout << getNome() << " não tem mais Estus!" << std::endl;
        return;
    }
    estusCargas--;
    curar(estusRecuperacao);
    std::cout << getNome() << " usa Frasco Estus — +" << estusRecuperacao
              << " HP! (" << estusCargas << " cargas restantes)" << std::endl;
}

void Personagem::recarregarEstus() { estusCargas = estusCargasMax; }

// ── habilidades ───────────────────────────────────────────────────────────────

void Personagem::adicionarHabilidade(Habilidade* h) {
    habilidades.push_back(h);
}

void Personagem::usarHabilidade(int idx, Entidade &alvo) {
    if (idx < 0 || idx >= static_cast<int>(habilidades.size())) {
        std::cout << "Habilidade inválida." << std::endl;
        return;
    }
    Habilidade* h = habilidades[idx];
    if (!h->podeUsar()) {
        std::cout << h->getNome() << " está em cooldown!" << std::endl;
        return;
    }
    if (!gastarStamina(h->getCustoStamina())) {
        std::cout << "Stamina insuficiente para " << h->getNome() << "!" << std::endl;
        return;
    }
    h->usar(*this, alvo);
}

void Personagem::reduzirCooldowns() {
    for (Habilidade* h : habilidades) h->reduzirCooldown();
}

// ── experiência / level up ────────────────────────────────────────────────────

void Personagem::ganharExp(int qt) {
    if (qt <= 0) return;
    exp += qt;
    std::cout << getNome() << " ganhou " << qt << " almas de experiência!" << std::endl;
    while (exp >= expProxNivel) {
        exp -= expProxNivel;
        levelUp();
    }
}

void Personagem::levelUp() {
    nivel++;
    expProxNivel = nivel * 500;
    forca       += 2;
    dex         += 2;
    staminaMax  += 10;
    stamina      = staminaMax;
    aumentarHPMax(50);
    std::cout << "══ LEVEL UP! " << getNome()
              << " chegou ao nível " << nivel << " ══" << std::endl;
}

// ── ataque ────────────────────────────────────────────────────────────────────

void Personagem::atacar(Entidade &alvo) {
    if (!estaVivo()) return;
    Arma* arma = inventario.getArmaEquipada();
    int dano;
    if (arma) {
        dano = arma->calcularDano(forca, dex) - alvo.getHPMax() / 20;
        dano = std::max(1, dano);
        std::cout << getNome() << " ataca com " << arma->getNome()
                  << " causando " << dano << " de dano em " << alvo.getNome() << "!" << std::endl;
    } else {
        dano = forca * 2;
        std::cout << getNome() << " ataca desarmado causando "
                  << dano << " de dano em " << alvo.getNome() << "!" << std::endl;
    }
    // Reduz pelo equipamento do alvo (se for Personagem)
    Personagem* p = dynamic_cast<Personagem*>(&alvo);
    if (p) dano = std::max(1, dano - p->getInventario().getDefesaTotal() / 5);
    alvo.receberDano(dano);
}

// ── exibição ──────────────────────────────────────────────────────────────────

void Personagem::exibirStatus() const {
    std::cout << "┌─────────────────────────────────────────┐\n"
              << "│ " << nome << " [" << raca->getNome() << "]\n"
              << "│ Nível: "    << nivel
              << " | Classe: "  << getClasse() << "\n"
              << "│ HP:      "  << hpAtual << "/" << hpMax << "\n"
              << "│ Stamina: "  << stamina << "/" << staminaMax << "\n"
              << "│ Estus:   "  << estusCargas << "/" << estusCargasMax << "\n"
              << "│ EXP:     "  << exp << "/" << expProxNivel << "\n"
              << "│ Força:   "  << forca
              << " | Dex: "     << dex
              << " | Intel: "   << inteligencia
              << " | Fé: "      << fe << "\n"
              << "│ Equipamento:\n";
    inventario.exibirEquipamento();
    std::cout << "└─────────────────────────────────────────┘" << std::endl;
}

} // namespace RPG