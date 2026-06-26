/**
 * @file classes.h
 * @brief Classes de personagem jogáveis inspiradas em Dark Souls 1.
 */
#ifndef CLASSES_H
#define CLASSES_H

#include "personagem.h"

namespace RPG {

// ── Cavaleiro ─────────────────────────────────────────────────────────────────

/**
 * @brief Cavaleiro — tanque, alta força e vitalidade.
 *
 * Habilidades: Ataque Pesado, Iron Flesh.
 * Level up: +1 força extra e +25 HP além do base.
 */
class Cavaleiro : public Personagem {
    public:
        Cavaleiro(const std::string &nm, Raca* raca);
        std::string getClasse() const override;
        void levelUp() override;
};

// ── Piromante ─────────────────────────────────────────────────────────────────

/**
 * @brief Piromante — dano mágico de fogo e gerenciamento de mana.
 *
 * Único personagem com sistema de mana além de stamina.
 * Habilidades: Piromancia (Grande Bola de Fogo), Alma Torrencial.
 */
class Piromante : public Personagem {
    private:
        int mana;
        int manaMax;

    public:
        Piromante(const std::string &nm, Raca* raca);

        int getMana()    const;
        int getManaMax() const;

        std::string getClasse() const override;
        void levelUp()          override;
        void exibirStatus()     const override;
};

// ── Ladino ────────────────────────────────────────────────────────────────────

/**
 * @brief Ladino — alta dex e ataques furtivos críticos.
 *
 * Modo furtivo duplica o dano do próximo ataque.
 * Habilidade: Punhalada pelas Costas.
 */
class Ladino : public Personagem {
    private:
        bool furtivo;

    public:
        Ladino(const std::string &nm, Raca* raca);

        bool isFurtivo()    const;
        void ativarFurtivo();

        std::string getClasse() const override;
        void levelUp()          override;

        /** @brief Ataque com dano dobrado se modo furtivo ativo. */
        void atacar(Entidade &alvo) override;
};

// ── Clérigo ───────────────────────────────────────────────────────────────────

/**
 * @brief Clérigo — suporte e cura. Alta fé e cargas de Estus extras.
 *
 * Habilidades: Emissão de Luz (cura), Ataque Pesado.
 */
class Clerigo : public Personagem {
    public:
        Clerigo(const std::string &nm, Raca* raca);
        std::string getClasse() const override;
        void levelUp()          override;
};

} // namespace RPG
#endif