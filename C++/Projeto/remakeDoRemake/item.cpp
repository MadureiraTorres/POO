/**
 * @file item.cpp
 * @brief Implementação da hierarquia de itens.
 */
#include "item.h"

namespace RPG {

// ── Item ─────────────────────────────────────────────────────────────────────

Item::Item(const std::string &nm, const std::string &desc, int peso, int valor)
    : nome(nm), descricao(desc), peso(peso), valor(valor) {}

std::string Item::getNome()      const { return nome; }
std::string Item::getDescricao() const { return descricao; }
int         Item::getPeso()      const { return peso; }
int         Item::getValor()     const { return valor; }

bool  Item::operator< (const Item &o) const { return valor < o.valor; }
bool  Item::operator==(const Item &o) const { return nome  == o.nome; }
Item* Item::operator+ (const Item &)  const { return nullptr; } // stub crafting

std::ostream &operator<<(std::ostream &os, const Item &i) {
    os << "[" << i.getTipo() << "] " << i.nome
       << " | Peso: " << i.peso << " | Valor: " << i.valor << " almas";
    return os;
}

// ── Arma ─────────────────────────────────────────────────────────────────────

Arma::Arma(const std::string &nm, const std::string &desc,
           int peso, int valor,
           int dano, int esc_forca, int esc_dex,
           const std::string &tipo)
    : Item(nm, desc, peso, valor),
      danoBase(dano), escalForca(esc_forca), escalDex(esc_dex), tipoArma(tipo) {}

int         Arma::getDanoBase()   const { return danoBase; }
int         Arma::getEscalForca() const { return escalForca; }
int         Arma::getEscalDex()   const { return escalDex; }
std::string Arma::getTipoArma()   const { return tipoArma; }
std::string Arma::getTipo()       const { return "Arma"; }

int Arma::calcularDano(int forca, int dex) const {
    return danoBase + (forca * escalForca / 10) + (dex * escalDex / 10);
}

void Arma::descrever() const {
    std::cout << *this << "\n"
              << "  Tipo: " << tipoArma
              << " | Dano base: " << danoBase
              << " | Esc. Força: " << escalForca
              << " | Esc. Dex: "   << escalDex << "\n"
              << "  \"" << descricao << "\"" << std::endl;
}

// ── Armadura ─────────────────────────────────────────────────────────────────

Armadura::Armadura(const std::string &nm, const std::string &desc,
                   int peso, int valor,
                   int def_fis, int def_mag, int def_fogo,
                   const std::string &slot)
    : Item(nm, desc, peso, valor),
      defesaFisica(def_fis), defesaMagica(def_mag),
      defesaFogo(def_fogo), slot(slot) {}

int         Armadura::getDefesaFisica() const { return defesaFisica; }
int         Armadura::getDefesaMagica() const { return defesaMagica; }
int         Armadura::getDefesaFogo()   const { return defesaFogo; }
std::string Armadura::getSlot()         const { return slot; }
std::string Armadura::getTipo()         const { return "Armadura"; }

void Armadura::descrever() const {
    std::cout << *this << "\n"
              << "  Slot: "         << slot
              << " | Def. Física: " << defesaFisica
              << " | Def. Mágica: " << defesaMagica
              << " | Def. Fogo: "   << defesaFogo << "\n"
              << "  \"" << descricao << "\"" << std::endl;
}

// ── Poção ─────────────────────────────────────────────────────────────────────

Pocao::Pocao(const std::string &nm, const std::string &desc,
             int peso, int valor, int cura, int cargas)
    : Item(nm, desc, peso, valor),
      cura(cura), cargasMax(cargas), cargasAtuais(cargas) {}

int  Pocao::getCura()   const { return cura; }
int  Pocao::getCargas() const { return cargasAtuais; }
bool Pocao::temCargas() const { return cargasAtuais > 0; }
std::string Pocao::getTipo() const { return "Consumível"; }

void Pocao::usar() {
    if (!temCargas()) throw std::runtime_error("Sem cargas: " + nome);
    cargasAtuais--;
}

void Pocao::recarregar() { cargasAtuais = cargasMax; }

void Pocao::descrever() const {
    std::cout << *this << "\n"
              << "  Cura: " << cura
              << " HP | Cargas: " << cargasAtuais << "/" << cargasMax << "\n"
              << "  \"" << descricao << "\"" << std::endl;
}

// ── Item Especial ─────────────────────────────────────────────────────────────

ItemEspecial::ItemEspecial(const std::string &nm, const std::string &desc,
                           int peso, int valor, const std::string &ef)
    : Item(nm, desc, peso, valor), efeito(ef), usado(false) {}

std::string ItemEspecial::getEfeito() const { return efeito; }
bool        ItemEspecial::foiUsado()  const { return usado; }
std::string ItemEspecial::getTipo()   const { return "Especial"; }

void ItemEspecial::ativar() {
    if (usado) throw std::runtime_error(nome + " já foi usado.");
    usado = true;
    std::cout << "✦ " << nome << " ativado! Efeito: " << efeito << std::endl;
}

void ItemEspecial::descrever() const {
    std::cout << *this << "\n"
              << "  Efeito: " << efeito
              << " | Status: " << (usado ? "Usado" : "Disponível") << "\n"
              << "  \"" << descricao << "\"" << std::endl;
}

} // namespace RPG