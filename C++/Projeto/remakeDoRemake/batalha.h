/**
 * @file batalha.h
 * @brief Sistema de batalha por turnos com log de ações.
 */
#ifndef BATALHA_H
#define BATALHA_H

#include "personagem.h"
#include "inimigo.h"
#include <vector>
#include <string>

namespace RPG {

/** @brief Registro de uma ação num turno de batalha. */
struct LogBatalha {
    int         turno;
    std::string descricao;
};

/**
 * @brief Gerencia o loop de combate por turnos entre Personagem e Inimigo.
 *
 * Implementa padrão Observer de forma simplificada via log de eventos:
 * cada ação relevante é registrada e pode ser consultada após a batalha.
 */
class Batalha {
    private:
        Personagem&             jogador;
        Inimigo&                inimigo;
        std::vector<LogBatalha> log;
        int                     turnoAtual;
        bool                    encerrada;

        void registrar(const std::string &msg);
        void imprimirSeparador() const;

        // ── ações do jogador ────────────────────────────────────────────────────
        void menuAcaoJogador();
        void menuHabilidade();
        void menuItem();

    public:
        /**
         * @brief Constrói a batalha entre jogador e inimigo.
         * @param j Personagem jogador (referência — não transfere ownership).
         * @param i Inimigo (referência — não transfere ownership).
         */
        Batalha(Personagem &j, Inimigo &i);

        /**
         * @brief Executa o loop de batalha por turnos.
         * @return true se o jogador venceu.
         */
        bool executar();

        /**
         * @brief Resolve o fim da batalha, distribuindo recompensas.
         * @return true se jogador sobreviveu.
         */
        bool resolverFim();

        /** @brief Exibe o log completo de ações da batalha. */
        void exibirLog() const;
};

} // namespace RPG
#endif