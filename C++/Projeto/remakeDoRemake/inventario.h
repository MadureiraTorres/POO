/**
 * @file inventario.h
 * @brief Gerenciamento de inventário com composição de itens, peso e equipamentos.
 */
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "item.h"
#include <vector>
#include <algorithm>

namespace RPG {

/**
 * @brief Inventário com lista de itens, peso máximo e slots de equipamento.
 *
 * Composição: Personagem possui um Inventario.
 * Controla adição/remoção de itens respeitando peso máximo,
 * e gerencia quatro slots de armadura (capacete, peitoral, calças, luvas).
 */
class Inventario {
    private:
        std::vector<Item*> itens;
        int                pesoMax;
        int                pesoAtual;

        // slots de equipamento ativos
        Arma*     armaEquipada  = nullptr;
        Armadura* capaceteEquip = nullptr;
        Armadura* peitoralEquip = nullptr;
        Armadura* calcasEquip   = nullptr;
        Armadura* luvEquip      = nullptr;

    public:
        explicit Inventario(int pesoMax = 50);
        ~Inventario();

        // ── itens ──────────────────────────────────────────────────────────────
        /**
         * @brief Adiciona item ao inventário respeitando limite de peso.
         * @return true se adicionado com sucesso.
         */
        bool adicionarItem(Item* item);

        /**
         * @brief Remove e deleta item pelo nome.
         * @return true se encontrado e removido.
         */
        bool  removerItem(const std::string &nomeItem);
        Item* buscarItem(const std::string &nomeItem) const;

        // ── equipar ────────────────────────────────────────────────────────────
        bool equiparArma(const std::string &nomeArma);
        bool equiparArmadura(const std::string &nomeArmadura);
        void desequiparArma();

        // ── getters de equipamento ─────────────────────────────────────────────
        Arma* getArmaEquipada()  const;

        /**
         * @brief Soma defesa física de todas as peças equipadas.
         * @return Defesa física total.
         */
        int getDefesaTotal() const;

        // ── consumíveis ────────────────────────────────────────────────────────
        /** @brief Retorna primeira poção disponível no inventário, ou nullptr. */
        Pocao* getPocao() const;

        // ── exibição ───────────────────────────────────────────────────────────
        void listarItens()       const;
        void exibirEquipamento() const;

        int getPesoAtual() const;
        int getPesoMax()   const;
        const std::vector<Item*>& getItens() const;
};

} // namespace RPG
#endif