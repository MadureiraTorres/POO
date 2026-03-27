#6. Implemente um método factoryReset( ) para a classe Televisão que restaura todos os
#atributos (exceto powerOn) para os valores de fábrica.

class TV:
    def __init__(self):
        self.ligada = False
        self.volume = 0
        self.canal = 0
        self.mute = False
        self.canalAnterior = 0
        self.favoritos = []
        self.factoryReset()
    
    def factoryReset(self):
        self.ligada = False
        self.volume = 0
        self.canal = 0
        self.mute = False
        self.canalAnterior = 0
        self.favoritos = []

if __name__ == "__main__":
    tv = TV()
    tv.factoryReset()
    print(tv.ligada)
    print(tv.volume)
    print(tv.canal)
    print(tv.mute)
    print(tv.canalAnterior)
    print(tv.favoritos)
