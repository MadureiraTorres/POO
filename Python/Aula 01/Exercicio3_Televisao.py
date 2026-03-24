#Exercicio 3: Implemente classes em C++ e Python para representação de uma TV
#marca, modelo, estaLigada,volume,estaMutada,canal,canalAnterior
#ligar(), desligar(), aumentarVolume(), diminuirVolume(), mutar(), desmutar(), proximoCanal(), voltarCanal(), acessarCanal(numeroCanal)

class TV:

    def __init__(self):
        self.__estaLigada = False
        self.__estaMutada = False
        self.__volume = 5
        self.__canal = 2
        self.__canalAnterior = 2

    def ligar(self):
        self.__estaLigada = not self.__estaLigada
    
    def desligar(self):
        if self.__estaLigada:
            self.__estaMutada = not self.__estaMutada
    
    def aumentarVolume(self):
        if self.__estaLigada:
            if self.__volume <10:
                self.__volume +=1
            self.__estaMutada = False
            return self.__volume
    
    def proximoCanal(self):
        if self.__estaLigada:
            self.__canalAnterior = self.__canal
            if self.__canal == 99:
                self.__canal = 2
            else:
                self.__canal +=1
            return self.__canal
        
    def acessarCanal(self, numeroCanal):
        if self.__estaLigada:
            if 2 <= numeroCanal <= 99:
                self.__canalAnterior = self.__canal
                self.__canal = numeroCanal 
            return self.__canal
    
    def voltarCanal(self):
        if self.__estaLigada:
            incoming = self.__canal
            self.__canal = self.__canalAnterior 
            self.__canalAnterior = incoming
            return self.__canal
    
    def __str__(self):
        display = 'O estado da TV é atualmente: ' + str(self.__estaLigada) +'\n'
        display += 'O canal atual é: ' + str(self.__canal) +'\n'
        display += 'O volume atual é: ' + str(self.__volume) +'\n'
        display += 'O mute está: ' + str(self.__estaMutada)
        return display


if __name__ == "__main__":
    tv = TV()
    print(type(tv))
    print(tv)
