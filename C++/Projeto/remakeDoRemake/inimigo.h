/**
 * @file inimigo.h
 * @brief Inimigos de Dark Souls 1 com comportamento via padrão Strategy.
 */
#ifndef INIMIGO_H
#define INIMIGO_H

#include "entidade.h"
#include <cstdlib>

namespace RPG {

// ── Strategy de comportamento de IA ──────────────────────────────────────────

/**
 * @brief Interface Strategy para comportamento de IA dos inimigos.
 */
class ComportamentoIA {
    public:
        virtual ~ComportamentoIA() = default;
        virtual void        agir(Entidade &self, Entidade &alvo) = 0;
        virtual std::string getNome() const = 0;
};

/** @brief IA agressiva: sempre ataca com dano máximo. */
class IAgressiva : public ComportamentoIA {
    public:
        std::string getNome() const override;
        void agir(Entidade &self, Entidade &alvo) override;
};

/** @brief IA cautelosa: ataca com 60% de chance, recua nos demais casos. */
class IACautelosa : public ComportamentoIA {
    public:
        std::string getNome() const override;
        void agir(Entidade &self, Entidade &alvo) override;
};

/**
 * @brief IA de Boss: alterna entre ataque normal e especial a cada 3 turnos.
 */
class IABoss : public ComportamentoIA {
    private:
        int turno = 0;

    public:
        std::string getNome() const override;
        void agir(Entidade &self, Entidade &alvo) override;
};

// ── Inimigo base ──────────────────────────────────────────────────────────────

/**
 * @brief Inimigo com IA plugável via Strategy.
 *
 * Composição: Inimigo é dono do ComportamentoIA* e o deleta no destrutor.
 */
class Inimigo : public Entidade {
    protected:
        int              expRecompensa;
        int              almasRecompensa;
        ComportamentoIA* ia;

    public:
        Inimigo(const std::string &nm, int hp, int lv,
                int exp, int almas, ComportamentoIA* ia);
        virtual ~Inimigo();

        int getExpRecompensa()   const;
        int getAlmasRecompensa() const;

        void atacar(Entidade &alvo)  override;
        void exibirStatus()    const override;
};

// ── Inimigos concretos de Dark Souls 1 ────────────────────────────────────────

/** @brief Inimigo básico de nível 1 com IA cautelosa. */
class HollowSoldier : public Inimigo {
    public:
        HollowSoldier();
};

/** @brief Cavaleiro Negro — inimigo de elite, nível 5, IA agressiva. */
class BlackKnight : public Inimigo {
    public:
        BlackKnight();
};

/** @brief Catavento — boss de nível 8 com IA de boss. */
class PinwheelBoss : public Inimigo {
    public:
        PinwheelBoss();
};

/** @brief Gárgula da Torre Bell — boss de nível 10. */
class GargoyleBoss : public Inimigo {
    public:
        GargoyleBoss();
};

/** @brief Ornstein, o Caçador de Dragões — boss final, nível 20. */
class OrnsSteinBoss : public Inimigo {
    public:
        OrnsSteinBoss();
};

} // namespace RPG
#endif