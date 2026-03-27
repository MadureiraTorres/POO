#5. Nosso design de Televisão (código da aula) é feito de maneira que a informação atual
#é mantida, mesmo que o aparelho seja desligado. Assim, quando ela é ligado novamente,
#as configurações de volume, canal, e mute continuam como estavam. Entretanto, muitas
#televisões reais tem um comportamento diferente: mesmo que estivessem mutadas quando
#foram desligadas, quando são ligadas novamente o volume não está mais mutado. Altere os
#métodos e funções da implementação de Televisão para adotar esse comportamento.

class Televisao:
    def __init__(self):
        self._ligada = False
        self._volume = 5
        self._canal = 1
        self._mute = False
    
    def ligarDesligar(self):
        self._ligada = not self._ligada
    
    def setVolume(self, volume):
        if self._ligada:
            self._volume = volume
    
    def aumentarVolume(self):
        if self._ligada:
            self._volume = self._volume + 1
    
    def diminuirVolume(self):
        if self._ligada:
            self._volume = self._volume - 1
    
    def setCanal(self, canal):
        if self._ligada:
            self._canal = canal
    
    def aumentarCanal(self):
        if self._ligada:
            self._canal = self._canal + 1
    
    def diminuirCanal(self):
        if self._ligada:
            self._canal = self._canal - 1
    
    def mudo(self):
        if self._ligada:
            self._mute = not self._mute
    
    def __str__(self):
        return f"Power: {'On' if self._ligada else 'Off'}, Volume: {self._volume}, Channel: {self._canal}, Mute: {'On' if self._mute else 'Off'}"

if __name__ == "__main__":
    tv = Televisao()
    tv.ligarDesligar()
    tv.aumentarVolume()
    tv.setCanal(5)
    tv.mudo()
    tv.ligarDesligar()
    print(tv)
    print(tv._volume)
    print(tv._canal)
    print(tv._mute) 
