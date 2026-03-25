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

    def __init__(self):
        self.__nome = "Hagnar"
        self.__classe = "Arqueiro"
        self.__vida = 1000
        self.__nivel = 1
        self.__almas = 1
        self.__vitalidade = 10
        self.__conhecimento = 10
        self.__fortitude = 10
        self.__forca = 50
        self.__destreza = 100
        self.__resistencia = 500
        self.__inteligencia = 500
        self.__fe = 100

    def __str__(self):
        display = 'O nome do jogador é:' + str(self.__nome) + '\n'
        display += 'Sua classe é: ' + str(self.__classe) + '\n'
        display += 'Seu nivel de vida atual é: ' + str(self.__vida) + '\n'
        display += 'Seu nivel de experiencia atual é: ' + str(self.__nivel) + '\n'
        display += 'Seu nivel de almas atual é: ' + str(self.__almas) + '\n'
        display += 'Seu nivel de vitalidade atual é: ' + str(self.__vitalidade) + '\n'
        display += 'Seu nivel de conhecimento atual é: ' + str(self.__conhecimento) + '\n'
        display += 'Seu nivel de fortitude atual é: ' + str(self.__fortitude) + '\n'
        display += 'Seu nivel de força atual é: ' + str(self.__forca) + '\n'
        display += 'Seu nivel de destreza atual é: ' + str(self.__destreza) + '\n'
        display += 'Seu nivel de resistencia atual é: ' + str(self.__resistencia) + '\n'
        display += 'Seu nivel de Inteligencia atual é: ' + str(self.__inteligencia) + '\n'
        display += 'Seu nivel de Fé atual é: ' + str(self.__fe) + '\n'
        
        return display

    
if __name__ == "__main__":
    jogador = Jogador()
    print(type(jogador))
    print(jogador)
