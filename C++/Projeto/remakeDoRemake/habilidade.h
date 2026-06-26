/**
 * @file habilidade.h
 * @brief Sistema de habilidades ativas e passivas inspiradas em Dark Souls 1.
 */
#ifndef HABILIDADE_H
#define HABILIDADE_H

#include "entidade.h"
#include <iostream>

namespace RPG {

/**
 * @brief Classe abstrata base para todas as habilidades.
 */
class Habilidade {
    protected:
        std::string nome;
        std::string descricao;
        int         custoStamina;
        int         cooldownMax;
        int         cooldownAtual;

    public:
        Habilidade(const std::string &nm, const std::string &desc,
                   int stamina, int cd);
        virtual ~Habilidade() = default;

        std::string getNome()         const;
        std::string getDescricao()    const;
        int         getCustoStamina() const;
        bool        podeUsar()        const;

        void reduzirCooldown();
        void resetarCooldown();

        /**
         * @brief Executa o efeito da habilidade.
         * @param usuario Entidade que usa a habilidade.
         * @param alvo    Entidade alvo do efeito.
         */
        virtual void        usar(Entidade &usuario, Entidade &alvo) = 0;
        virtual std::string getTipo() const = 0;

        friend std::ostream &operator<<(std::ostream &os, const Habilidade &h);
};

// ── Ofensivas ─────────────────────────────────────────────────────────────────

/** @brief Golpe pesado com as duas mãos — alto dano e custo. */
class AtaquePesado : public Habilidade {
    public:
        AtaquePesado();
        std::string getTipo() const override;
        void usar(Entidade &usuario, Entidade &alvo) override;
};

/** @brief Projétil de fogo — dano mágico baseado em nível. */
class Piromancia : public Habilidade {
    public:
        Piromancia();
        std::string getTipo() const override;
        void usar(Entidade &usuario, Entidade &alvo) override;
};

/** @brief Crítico devastador pelas costas. */
class PunhaladaCostas : public Habilidade {
    public:
        PunhaladaCostas();
        std::string getTipo() const override;
        void usar(Entidade &usuario, Entidade &alvo) override;
};

// ── Defensivas ────────────────────────────────────────────────────────────────

/** @brief Piromancia defensiva: absorve dano por um turno. */
class IronFlesh : public Habilidade {
    public:
        IronFlesh();
        std::string getTipo() const override;
        void usar(Entidade &usuario, Entidade &alvo) override;
};

// ── Suporte ───────────────────────────────────────────────────────────────────

/** @brief Milagre sagrado que restaura HP. */
class MiraculoCura : public Habilidade {
    public:
        MiraculoCura();
        std::string getTipo() const override;
        void usar(Entidade &usuario, Entidade &alvo) override;
};

/** @brief Drena alma do inimigo, restaurando HP do usuário. */
class AlmaTorrencial : public Habilidade {
    public:
        AlmaTorrencial();
        std::string getTipo() const override;
        void usar(Entidade &usuario, Entidade &alvo) override;
};

} // namespace RPG
#endif