# Projeto: Classe de Jogador de RPG inspirado em DS
# nome: Nome do Jogador
# classe: Classe inicial (influencia apenas os atributos iniciais e o equipamento)
# vida: Atributo HP (pontos de vida), aumenta principalmente com Vitalidade
# stamina: Barra de energia; em DS1, ela aumenta exclusivamente com Fortitude
# nivel: Nível de Alma (Soul Level); aumenta a cada ponto gasto em atributos
# almas: Moeda principal para comércio e para subir de nível nos Bonfires
# vitalidade: Aumenta o HP máximo e a resistência física global
# conhecimento: Aumenta o número de slots (espaços) para equipar Magias, Milagres e Piromancias
# fortitude: Aumenta a Stamina, a Carga de Equipamento (Equip Load) e a Resistência a Sangramento
# forca: Requisito para armas pesadas; aumenta o dano de armas com escalonamento em Força
# destreza: Requisito para armas ágeis; aumenta o dano de armas "Dex" e reduz o tempo de cast de magias
# resistencia: Aumenta a defesa física e a resistência a Veneno (considerado o atributo menos útil do jogo)
# inteligencia: Requisito para usar Sorceries (Feitiçarias); aumenta o dano de catalisadores e armas mágicas
# fe: Requisito para usar Milagres; aumenta o poder de talismãs e armas divinas/ocultas


class Jogador:
    def __init__(self, nome, classe, vida, stamina, nivel, almas, vitalidade, conhecimento, fortitude, forca, destreza, resistencia, inteligencia, fe):
        self.nome = nome
        self.classe = classe
        self.vida = vida                    # upa com vitalidade
        self.stamina = stamina              # upa com fortitude (Resistance no DS só aumenta defesa de poison, é meme)
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

    def exibirStatus(self):
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

    def estaVivo(self):
        return self.vida > 0

    def receberDano(self, dano):
        if dano > 0:
            self.vida -= dano
            if self.vida < 0:
                self.vida = 0
            print(f"{self.nome} recebeu {dano} de dano! Vida restante: {self.vida}")

    def curar(self, quantidade):
        if quantidade > 0 and self.estaVivo():
            self.vida += quantidade
            print(f"{self.nome} foi curado em {quantidade} pontos! Vida atual: {self.vida}")


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

    jogador1.exibirStatus()
    print()
    jogador1.receberDano(100)
    print()
    jogador1.curar(50)
    print()
    jogador1.exibirStatus()
