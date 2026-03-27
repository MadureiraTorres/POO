#7. Defina uma classe Conjunto, que mantém o controle de uma coleção de objetos distintos. Internamente, use uma lista como uma variável de controle, mas sem permitir valores
#duplicados em seu conteúdo. A seguinte sugestão de design pode ser adotada:
#O método para adicionar elementos deve inserir o elemento no conjunto se ele não existir.
#O método para remover deve remover um elemento apenas se ele existir no conjunto. O método pesquisar retorna True/False se o elemento existe ou não dentro do conjunto.

#CONJUTNO
#__conjunto
#Conjunto()
#adicionar(valor)
#remover(valor)
#pesquisar(valor)

class Conjunto:
    def __init__(self):
        self.__conjunto = []

    def adicionar(self, valor):
        if valor not in self.__conjunto:
            self.__conjunto.append(valor)
    
    def remover(self, valor):
        if valor in self.__conjunto:
            self.__conjunto.remove(valor)
    
    def pesquisar(self, valor):
        return valor in self.__conjunto
    
    def exibirConjunto(self):
        print(self.__conjunto)

if __name__ == "__main__":
    conjunto = Conjunto()
    conjunto.adicionar(1)
    conjunto.adicionar(2)
    conjunto.adicionar(3)
    conjunto.adicionar(1)
    conjunto.remover(2)
    conjunto.pesquisar(1)
    conjunto.exibirConjunto()
