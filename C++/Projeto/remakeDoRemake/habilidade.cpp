/**
 * @file habilidade.cpp
 * @brief Implementação do sistema de habilidades.
 */
#include "habilidade.h"

namespace RPG {

// ── Habilidade base ───────────────────────────────────────────────────────────

Habilidade::Habilidade(const std::string &nm, const std::string &desc,
                       int stamina, int cd)
    : nome(nm), descricao(desc),
      custoStamina(stamina), cooldownMax(cd), cooldownAtual(0) {}

std::string Habilidade::getNome()         const { return nome; }
std::string Habilidade::getDescricao()    const { return descricao; }
int         Habilidade::getCustoStamina() const { return custoStamina; }
bool        Habilidade::podeUsar()        const { return cooldownAtual == 0; }

void Habilidade::reduzirCooldown() { if (cooldownAtual > 0) cooldownAtual--; }
void Habilidade::resetarCooldown() { cooldownAtual = cooldownMax; }

std::ostream &operator<<(std::ostream &os, const Habilidade &h) {
    os << "[" << h.getTipo() << "] " << h.nome << " — " << h.descricao
       << " (stamina: " << h.custoStamina << ", CD: " << h.cooldownMax << ")";
    return os;
}

// ── AtaquePesado ──────────────────────────────────────────────────────────────

AtaquePesado::AtaquePesado()
    : Habilidade("Ataque Pesado",
                 "Golpe poderoso com as duas mãos. Alto dano, abre guarda.",
                 40, 1) {}

std::string AtaquePesado::getTipo() const { return "Ofensiva"; }

void AtaquePesado::usar(Entidade &usuario, Entidade &alvo) {
    int dano = usuario.getNivel() * 25 + 30;
    std::cout << usuario.getNome() << " desfere um ATAQUE PESADO em "
              << alvo.getNome() << " causando " << dano << " de dano!" << std::endl;
    alvo.receberDano(dano);
    resetarCooldown();
}

// ── Piromancia ────────────────────────────────────────────────────────────────

Piromancia::Piromancia()
    : Habilidade("Grande Bola de Fogo",
                 "Projétil de fogo intenso. Causa dano em área.",
                 35, 2) {}

std::string Piromancia::getTipo() const { return "Ofensiva"; }

void Piromancia::usar(Entidade &usuario, Entidade &alvo) {
    int dano = usuario.getNivel() * 20 + 40;
    std::cout << usuario.getNome() << " lança GRANDE BOLA DE FOGO em "
              << alvo.getNome() << " causando " << dano << " de dano de fogo!" << std::endl;
    alvo.receberDano(dano);
    resetarCooldown();
}

// ── PunhaladaCostas ───────────────────────────────────────────────────────────

PunhaladaCostas::PunhaladaCostas()
    : Habilidade("Punhalada pelas Costas",
                 "Crítico devastador ao posicionar atrás do inimigo.",
                 20, 3) {}

std::string PunhaladaCostas::getTipo() const { return "Ofensiva"; }

void PunhaladaCostas::usar(Entidade &usuario, Entidade &alvo) {
    int dano = usuario.getNivel() * 35 + 20;
    std::cout << usuario.getNome() << " executa PUNHALADA PELAS COSTAS em "
              << alvo.getNome() << " — CRÍTICO! " << dano << " de dano!" << std::endl;
    alvo.receberDano(dano);
    resetarCooldown();
}

// ── IronFlesh ─────────────────────────────────────────────────────────────────

IronFlesh::IronFlesh()
    : Habilidade("Iron Flesh",
                 "Piromancia defensiva: torna a carne em ferro por um turno.",
                 25, 3) {}

std::string IronFlesh::getTipo() const { return "Defensiva"; }

void IronFlesh::usar(Entidade &usuario, Entidade &alvo) {
    (void)alvo;
    int cura = usuario.getNivel() * 10 + 50;
    std::cout << usuario.getNome() << " ativa IRON FLESH — absorve "
              << cura << " de dano como escudo!" << std::endl;
    usuario.curar(cura);
    resetarCooldown();
}

// ── MiraculoCura ──────────────────────────────────────────────────────────────

MiraculoCura::MiraculoCura()
    : Habilidade("Emissão de Luz",
                 "Milagre sagrado que restaura pontos de vida.",
                 15, 2) {}

std::string MiraculoCura::getTipo() const { return "Suporte"; }

void MiraculoCura::usar(Entidade &usuario, Entidade &alvo) {
    (void)alvo;
    int cura = usuario.getNivel() * 15 + 60;
    std::cout << usuario.getNome() << " conjura EMISSÃO DE LUZ — recupera "
              << cura << " HP!" << std::endl;
    usuario.curar(cura);
    resetarCooldown();
}

// ── AlmaTorrencial ────────────────────────────────────────────────────────────

AlmaTorrencial::AlmaTorrencial()
    : Habilidade("Alma Torrencial",
                 "Magia que drena a alma do inimigo, restaurando HP do usuário.",
                 30, 3) {}

std::string AlmaTorrencial::getTipo() const { return "Suporte"; }

void AlmaTorrencial::usar(Entidade &usuario, Entidade &alvo) {
    int drain = usuario.getNivel() * 12 + 30;
    std::cout << usuario.getNome() << " usa ALMA TORRENCIAL em "
              << alvo.getNome() << " — drena " << drain << " HP!" << std::endl;
    alvo.receberDano(drain);
    usuario.curar(drain / 2);
}

} // namespace RPG