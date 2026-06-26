/**
 * @file raca.h
 * @brief Raças jogáveis inspiradas no lore de Dark Souls 1.
 */
#ifndef RACA_H
#define RACA_H

#include <string>

namespace RPG {

/**
 * @brief Base abstrata para raças. Encapsula bônus de atributos e lore.
 */
class Raca {
    public:
        virtual ~Raca() = default;

        virtual std::string getNome()    const = 0;
        virtual std::string getLore()    const = 0;
        virtual int bonusHP()            const = 0;
        virtual int bonusForca()         const = 0;
        virtual int bonusDex()           const = 0;
        virtual int bonusIntel()         const = 0;
        virtual int bonusFe()            const = 0;
        virtual int bonusVital()         const = 0;
};

/** @brief Humanos: versáteis, sem bônus extremos. */
class Humano : public Raca {
    public:
        std::string getNome()  const override;
        std::string getLore()  const override;
        int bonusHP()          const override;
        int bonusForca()       const override;
        int bonusDex()         const override;
        int bonusIntel()       const override;
        int bonusFe()          const override;
        int bonusVital()       const override;
};

/** @brief Morto-Vivo: resistente, HP e força extras. */
class MortoVivo : public Raca {
    public:
        std::string getNome()  const override;
        std::string getLore()  const override;
        int bonusHP()          const override;
        int bonusForca()       const override;
        int bonusDex()         const override;
        int bonusIntel()       const override;
        int bonusFe()          const override;
        int bonusVital()       const override;
};

/** @brief Pygmy: fraco fisicamente, inteligência e fé elevadas. */
class Pygmy : public Raca {
    public:
        std::string getNome()  const override;
        std::string getLore()  const override;
        int bonusHP()          const override;
        int bonusForca()       const override;
        int bonusDex()         const override;
        int bonusIntel()       const override;
        int bonusFe()          const override;
        int bonusVital()       const override;
};

/** @brief Dragão Antigo: força e resistência brutais, sem magia. */
class DragaoAntigo : public Raca {
    public:
        std::string getNome()  const override;
        std::string getLore()  const override;
        int bonusHP()          const override;
        int bonusForca()       const override;
        int bonusDex()         const override;
        int bonusIntel()       const override;
        int bonusFe()          const override;
        int bonusVital()       const override;
};

} // namespace RPG
#endif