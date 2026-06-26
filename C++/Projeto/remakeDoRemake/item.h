/**
 * @file item.h
 * @brief Hierarquia de itens do RPG Manager.
 */
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <stdexcept>

namespace RPG {

/**
 * @brief Classe base abstrata para todos os itens.
 */
class Item {
    protected:
        std::string nome;
        std::string descricao;
        int         peso;
        int         valor;

    public:
        Item(const std::string &nm, const std::string &desc, int peso, int valor);
        virtual ~Item() = default;

        std::string getNome()      const;
        std::string getDescricao() const;
        int         getPeso()      const;
        int         getValor()     const;

        virtual void        descrever() const = 0;
        virtual std::string getTipo()   const = 0;

        bool  operator< (const Item &o) const;
        bool  operator==(const Item &o) const;
        Item* operator+ (const Item &)  const; // stub para crafting bônus

        friend std::ostream &operator<<(std::ostream &os, const Item &i);
};

// ── Arma ─────────────────────────────────────────────────────────────────────

/**
 * @brief Arma com escalonamento de dano por atributos.
 */
class Arma : public Item {
    private:
        int         danoBase;
        int         escalForca;
        int         escalDex;
        std::string tipoArma;

    public:
        Arma(const std::string &nm, const std::string &desc,
             int peso, int valor,
             int dano, int esc_forca, int esc_dex,
             const std::string &tipo);

        int         getDanoBase()   const;
        int         getEscalForca() const;
        int         getEscalDex()   const;
        std::string getTipoArma()   const;
        std::string getTipo()       const override;

        /**
         * @brief Calcula dano total considerando atributos do portador.
         * @param forca  Atributo de força do personagem.
         * @param dex    Atributo de destreza do personagem.
         * @return Dano total calculado.
         */
        int calcularDano(int forca, int dex) const;

        void descrever() const override;
};

// ── Armadura ─────────────────────────────────────────────────────────────────

/**
 * @brief Armadura com defesas físicas, mágicas e de fogo por slot.
 */
class Armadura : public Item {
    private:
        int         defesaFisica;
        int         defesaMagica;
        int         defesaFogo;
        std::string slot;

    public:
        Armadura(const std::string &nm, const std::string &desc,
                 int peso, int valor,
                 int def_fis, int def_mag, int def_fogo,
                 const std::string &slot);

        int         getDefesaFisica() const;
        int         getDefesaMagica() const;
        int         getDefesaFogo()   const;
        std::string getSlot()         const;
        std::string getTipo()         const override;

        void descrever() const override;
};

// ── Poção ─────────────────────────────────────────────────────────────────────

/**
 * @brief Consumível com cargas limitadas (Estus Flask e similares).
 */
class Pocao : public Item {
    private:
        int cura;
        int cargasMax;
        int cargasAtuais;

    public:
        Pocao(const std::string &nm, const std::string &desc,
              int peso, int valor, int cura, int cargas);

        int  getCura()   const;
        int  getCargas() const;
        bool temCargas() const;
        std::string getTipo() const override;

        /** @brief Consome uma carga. Lança runtime_error se sem cargas. */
        void usar();
        void recarregar();

        void descrever() const override;
};

// ── Item Especial ─────────────────────────────────────────────────────────────

/**
 * @brief Item de uso único com efeito especial.
 */
class ItemEspecial : public Item {
    private:
        std::string efeito;
        bool        usado;

    public:
        ItemEspecial(const std::string &nm, const std::string &desc,
                     int peso, int valor, const std::string &ef);

        std::string getEfeito() const;
        bool        foiUsado()  const;
        std::string getTipo()   const override;

        /** @brief Ativa o efeito. Lança runtime_error se já usado. */
        void ativar();

        void descrever() const override;
};

} // namespace RPG
#endif