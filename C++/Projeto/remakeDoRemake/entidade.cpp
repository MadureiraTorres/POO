/**
 * @file entidade.cpp
 * @brief Implementação da classe abstrata Entidade.
 */
#include "entidade.h"

namespace RPG {

Entidade::Entidade(const std::string &nm, int hp, int lv)
    : nome(nm), hpAtual(hp), hpMax(hp), nivel(lv)
{
    if (hp <= 0) throw std::invalid_argument("HP deve ser positivo");
    if (lv <= 0) throw std::invalid_argument("Nível deve ser positivo");
}

std::string Entidade::getNome()    const { return nome; }
int         Entidade::getHPAtual() const { return hpAtual; }
int         Entidade::getHPMax()   const { return hpMax; }
int         Entidade::getNivel()   const { return nivel; }

void Entidade::setNome(const std::string &nm) { nome = nm; }

void Entidade::setNivel(int lv) {
    if (lv <= 0) throw std::invalid_argument("Nível deve ser positivo");
    nivel = lv;
}

bool Entidade::estaVivo() const { return hpAtual > 0; }

void Entidade::receberDano(int dano) {
    if (dano <= 0 || !estaVivo()) return;
    hpAtual = std::max(0, hpAtual - dano);
}

void Entidade::curar(int cura) {
    if (cura <= 0 || !estaVivo()) return;
    hpAtual = std::min(hpMax, hpAtual + cura);
}

void Entidade::aumentarHPMax(int bonus) {
    hpMax   += bonus;
    hpAtual += bonus;
}

bool Entidade::operator==(const Entidade &o) const {
    return nome == o.nome && nivel == o.nivel;
}

bool Entidade::operator<(const Entidade &o) const {
    return nivel < o.nivel;
}

std::ostream &operator<<(std::ostream &os, const Entidade &e) {
    os << "[" << e.nome << " | Nível " << e.nivel
       << " | HP " << e.hpAtual << "/" << e.hpMax << "]";
    return os;
}

} // namespace RPG