/**
 * @file raca.cpp
 * @brief Implementação das raças jogáveis.
 */
#include "raca.h"

namespace RPG {

// ── Humano ────────────────────────────────────────────────────────────────────

std::string Humano::getNome()  const { return "Humano"; }
std::string Humano::getLore()  const {
    return "Descendentes da Chama Primordial, os humanos carregam "
           "a Marca Escura — amaldiçoados e abençoados ao mesmo tempo.";
}
int Humano::bonusHP()    const { return 50; }
int Humano::bonusForca() const { return 1; }
int Humano::bonusDex()   const { return 1; }
int Humano::bonusIntel() const { return 1; }
int Humano::bonusFe()    const { return 1; }
int Humano::bonusVital() const { return 1; }

// ── MortoVivo ────────────────────────────────────────────────────────────────

std::string MortoVivo::getNome()  const { return "Morto-Vivo"; }
std::string MortoVivo::getLore()  const {
    return "Marcados pela Marca Escura, os Mortos-Vivos ressurgem "
           "eternamente. Perdem a sanidade a cada morte, mas ganham "
           "resiliência incomparável.";
}
int MortoVivo::bonusHP()    const { return 100; }
int MortoVivo::bonusForca() const { return 2; }
int MortoVivo::bonusDex()   const { return 0; }
int MortoVivo::bonusIntel() const { return 0; }
int MortoVivo::bonusFe()    const { return 0; }
int MortoVivo::bonusVital() const { return 2; }

// ── Pygmy ─────────────────────────────────────────────────────────────────────

std::string Pygmy::getNome()  const { return "Pygmy"; }
std::string Pygmy::getLore()  const {
    return "Descendentes do Pigmeu, senhor da Alma Escura. "
           "São frágeis de corpo, mas detentores de sabedoria arcana "
           "e conexão profunda com os milagres.";
}
int Pygmy::bonusHP()    const { return 0; }
int Pygmy::bonusForca() const { return -1; }
int Pygmy::bonusDex()   const { return 1; }
int Pygmy::bonusIntel() const { return 3; }
int Pygmy::bonusFe()    const { return 3; }
int Pygmy::bonusVital() const { return 0; }

// ── DragaoAntigo ─────────────────────────────────────────────────────────────

std::string DragaoAntigo::getNome()  const { return "Dragão Antigo"; }
std::string DragaoAntigo::getLore()  const {
    return "Remanescentes da era anterior à Chama, os Dragões Antigos "
           "possuem escamas de pedra e resistência sobre-humana, "
           "mas são impermeáveis às artes arcanas.";
}
int DragaoAntigo::bonusHP()    const { return 150; }
int DragaoAntigo::bonusForca() const { return 4; }
int DragaoAntigo::bonusDex()   const { return 0; }
int DragaoAntigo::bonusIntel() const { return -3; }
int DragaoAntigo::bonusFe()    const { return -3; }
int DragaoAntigo::bonusVital() const { return 3; }

} // namespace RPG