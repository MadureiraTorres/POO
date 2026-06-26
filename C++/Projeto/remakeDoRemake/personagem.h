/**
 * @file personagem.h
 * @brief Classe Personagem: herda Entidade, possui Inventario e Habilidades.
 */
#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "entidade.h"
#include "raca.h"
#include "habilidade.h"
#include "inventario.h"
#include <vector>

namespace RPG {

/**
 * @brief Personagem jogável. Agrega Inventario (composição) e Habilidades.
 *
 * Relação com Raca: composição — Personagem é dono da Raca* e a deleta
 * no destrutor, pois cada personagem cria sua própria instância de raça.
 */
class Personagem : public Entidade {
    protected:
        int forca;
        int dex;
        int inteligencia;
        int fe;
        int vitalidade;
        int stamina;
        int staminaMax;
        int exp;
        int expProxNivel;
        int estusCargasMax;
        int estusCargas;
        int estusRecuperacao;

        Raca*                    raca;       ///< Composição — Personagem é dono
        Inventario               inventario; ///< Composição
        std::vector<Habilidade*> habilidades;///< Composição

    public:
        /**
         * @brief Constrói um personagem aplicando os bônus da raça.
         * @param raca Ponteiro para raça alocada no heap (ownership transferido).
         */
        Personagem(const std::string &nm, int lv, int hp,
                   int forca, int dex, int intel, int fe, int vital,
                   Raca* raca);

        /** @brief Deleta raça e habilidades (composição). */
        virtual ~Personagem();

        // ── getters ────────────────────────────────────────────────────────────
        int    getForca()        const;
        int    getDex()          const;
        int    getInteligencia() const;
        int    getFe()           const;
        int    getVitalidade()   const;
        int    getStamina()      const;
        int    getStaminaMax()   const;
        int    getExp()          const;
        int    getExpProxNivel() const;
        int    getEstusCargas()  const;
        Raca*  getRaca()         const;

        Inventario&       getInventario();
        const Inventario& getInventario() const;
        const std::vector<Habilidade*>& getHabilidades() const;

        // ── stamina ────────────────────────────────────────────────────────────
        bool gastarStamina(int custo);
        void recuperarStamina(int qt = 20);

        // ── estus ──────────────────────────────────────────────────────────────
        void usarEstus();
        void recarregarEstus();

        // ── habilidades ────────────────────────────────────────────────────────
        void adicionarHabilidade(Habilidade* h);

        /**
         * @brief Usa habilidade pelo índice no vetor.
         * @param idx   Índice da habilidade (0-based).
         * @param alvo  Entidade alvo.
         */
        void usarHabilidade(int idx, Entidade &alvo);
        void reduzirCooldowns();

        // ── experiência / level up ─────────────────────────────────────────────
        void ganharExp(int qt);

        /** @brief Aumenta nível e distribui pontos base. Sobrescrito pelas subclasses. */
        virtual void levelUp();

        // ── ataque e exibição ──────────────────────────────────────────────────
        void atacar(Entidade &alvo) override;
        void exibirStatus()         const override;

        /** @brief Retorna o nome da classe RPG do personagem. */
        virtual std::string getClasse() const = 0;
};

} // namespace RPG
#endif