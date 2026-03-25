#Projeto: Classe de Jogador de RPG
#nome;
#classe;
#vida; //upa com vitalidade
#stamina; //upa com resistência ou fortitude, não sei ainda
#nivel; //nivel aumenta conforme upamos os atributos abaixo
#almas; //moeda de compra e que também serve para upar os atributos 
#vitalidade; //quant de hp, quando eu abrir o jogo de novo eu vejo o que de sub-atributo upa com ele
#conhecimento; //quant de espaços para alocar magias, quando eu abrir o jogo de novo eu vejo o que de sub-atributo upa com ele
#fortitude; //quant de peso que o jogador pode carregar, responsavel tbm pelo poise, e a stamina é aqui ou na resistencia
#forca; //quant de dano causado com armas que usam esse atributo, serve como nota de corte pra usar armas de força
#destreza; //quant de dano causado com armas que usam esse atributo, serve como nota de corte pra usar armas de dex
#resistencia; //não me lembro se é aqui a stamina ou na fortitude
#inteligencia; //atributo para usar sorceries/sortilégios, nota de corte pra magias
#fe; //atributo pra usar milagres (e acho que tem uma piromância que tem dano base de fé)


class Jogador:
    def __init__(self, nome, classe, vida, stamina, nivel, almas, vitalidade, conhecimento, fortitude, forca, destreza, resistencia, inteligencia, fe):
        self.nome = nome
        self.classe = classe
        self.vida = vida                    # upa com vitalidade
        self.stamina = stamina              # upa com fortitude! (Resistance no DS1 só aumenta defesa de poison, é meme)
        self.nivel = nivel                  # nivel aumenta conforme upamos os atributos abaixo
        self.almas = almas                  # moeda de compra
        self.vitalidade = vitalidade        # quant de hp
        self.conhecimento = conhecimento    # quant de espaços para alocar magias
        self.fortitude = fortitude          # quant de peso e stamina
        self.forca = forca                  # quant de dano causado com armas pesadas
        self.destreza = destreza            # quant de dano causado com armas rapidas
        self.resistencia = resistencia      # defesa base (status inútil no DS1)
        self.inteligencia = inteligencia    # atributo para usar sorceries/sortilégios
        self.fe = fe                        # atributo pra usar milagres

    def exibir_status(self):
        print(f"Nome: {self.nome}")
        print(f"Classe: {self.classe}")
        print(f"Nivel: {self.nivel}")
        print(f"Vida: {self.vida}")
        print(f"Stamina: {self.stamina}")
        print(f"Almas: {self.almas}")
        print(f"Vitalidade: {self.vitalidade}")
        print(f"Conhecimento: {self.conhecimento}")
        print(f"Fortitude: {self.fortitude}")
        print(f"Forca: {self.forca}")
        print(f"Destreza: {self.destreza}")
        print(f"Resistencia: {self.resistencia}")
        print(f"Inteligencia: {self.inteligencia}")
        print(f"Fe: {self.fe}")


if __name__ == "__main__":
    # Criando um jogador
    jogador1 = Jogador(
        nome="Hargon",
        classe="Arqueiro",
        vida=1000,
        stamina=100,
        nivel=10,
        almas=10,
        vitalidade=10,
        conhecimento=10,
        fortitude=10,
        forca=10,
        destreza=10,
        resistencia=10,
        inteligencia=10,
        fe=10
    )

    jogador1.exibir_status()
    
