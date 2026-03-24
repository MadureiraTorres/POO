#Projeto: Classe de Jogador de RPG
class Jogador:

    def __init__(self):
        self.__nome = "Hagnar"
        self.__classe = "Arqueiro"
        self.__nivel = 10
        self.__vida = 1000
        self.__mana = 500

    def __str__(self):
        display = 'O nome do jogador é:' + str(self.__nome) + '\n'
        display += 'Sua classe é: ' + str(self.__classe) + '\n'
        display += 'Seu nivel atual é: ' + str(self.__nivel) + '\n'
        display += 'Sua vida atual é: ' + str(self.__vida)
        return display

    
if __name__ == "__main__":
    jogador = Jogador()
    print(type(jogador))
    print(jogador)
