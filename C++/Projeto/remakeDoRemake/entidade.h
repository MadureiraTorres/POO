/**
 * @file entidade.h
 * @brief Classe abstrata raiz de todas as entidades do RPG Manager.
 */
#ifndef ENTIDADE_H
#define ENTIDADE_H

#include <iostream>
#include <string>
#include <stdexcept>

namespace RPG {

/**
 * @brief Base abstrata para todo ser do jogo (personagens e inimigos).
 */
class Entidade {
    protected:
        std::string nome;
        int         hpAtual;
        int         hpMax;
        int         nivel;

    public:
        Entidade(const std::string &nm, int hp, int lv);
        virtual ~Entidade() = default;

        // getters
        std::string getNome()    const;
        int         getHPAtual() const;
        int         getHPMax()   const;
        int         getNivel()   const;

        // setters
        void setNome(const std::string &nm);
        void setNivel(int lv);

        bool estaVivo()          const;
        void receberDano(int dano);
        void curar(int cura);
        void aumentarHPMax(int bonus);

        // interface virtual pura
        virtual void exibirStatus()    const = 0;
        virtual void atacar(Entidade &alvo)  = 0;

        // sobrecarga de operadores
        bool operator==(const Entidade &o) const;
        bool operator< (const Entidade &o) const;

        friend std::ostream &operator<<(std::ostream &os, const Entidade &e);
};

} // namespace RPG
#endif