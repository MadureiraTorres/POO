#8. Incremente a classe Televisão para incorporar uma lista de canais favoritos como atributo. Três outros métodos precisam ser desenvolvidos:
#• addToFavorites( ) deve adicionar o canal atual na lista de canais favoritos, se não existir;
#• removeFromFavorites( ) deve remover o canal atual da lista de favoritos, se existir;
#• jumtToFavorite( ), deve trocar o canal atual para um canal que existe na lista de favoritos. Especificamente, o canal favorito a ser trocado deve ser o próximo valor acima do valor corrente do canal atual. Se não existir um valor maior do que o canal
#corrente, usar o menor valor entre todos os favoritos. Se a lista de favoritos for vazia,
#o canal não deverá ser trocado.
#Tome cuidado para que o método jumpToFavorite( ) mantenha as propriedades do atributo
#prevChannel para ser usado nas chamadas de jumpPrevChannel( ). 

class TV:
    def __init__(self):
        self.ligada = False
        self.volume = 0
        self.canal = 0
        self.mute = False
        self.canalAnterior = 0
        self.favoritos = []
    
    def ligarDesligar(self):
        self.ligada = not self.ligada
    
    def addToFavorites(self):
        if self.canal not in self.favoritos:
            self.favoritos.append(self.canal)
    
    def removeFromFavorites(self):
        if self.canal in self.favoritos:
            self.favoritos.remove(self.canal)
    
    def jumpToFavorite(self):
        if self.favoritos:
            self.canalAnterior = self.canal
            self.canal = min(self.favoritos)
            self.favoritos.remove(self.canal)
            self.favoritos.append(self.canalAnterior)
    

if __name__ == "__main__":
    tv = TV()
    tv.ligada = True
    tv.volume = 10
    tv.canal = 5
    tv.addToFavorites()
    tv.removeFromFavorites()
    tv.jumpToFavorite()
    print(tv.favoritos)
    print(tv.canalAnterior)
    print(tv.canal)
    print(tv.ligada)
    print(tv.volume)
    print(tv.mute)
    print(tv.favoritos)
