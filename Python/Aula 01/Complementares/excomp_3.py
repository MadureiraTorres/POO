#3. O código abaixo define uma classe Radio que implementa um modelo (muito) simples
#de rádio. Embora possa se criticar o realismo do modelo, há problemas mais sérios na
#modelagem. Especificamente, há 5 erros críticos com a sintaxe da classe definida. Identifique
#e os corrija.
#class Radio( ):
#def init(self):
#self._powerOn = False
#self._volume = 5
#self._station = 90.7
#self._presets = [90.7, 92.3, 94.7, 98.1, 105.7, 107.7]
#def tooglePower(self):
#self._powerOn = not self._powerOn
#def setPreset(self, ind):
#self._presets[ind] = _station
#def gotoPreset(self, ind):
#self._station = self._presets[ind]
#def increaseVolume(self):
#self._volume = self._volume + 1
#def decreaseVolume(self):
#self._volume = self._volume - 1
#def increaseStation(self):
#self._station = self._station + .2
#def decreaseStation(self):
#self._station = self._station - .2

class Radio:
    def __init__(self):
        self._ligada = False
        self._volume = 5
        self._estacao = 90.7
        self._predefinicoes = [90.7, 92.3, 94.7, 98.1, 105.7, 107.7]
    
    def ligarDesligar(self):
        self._ligada = not self._ligada
    
    def setPredefinicao(self, ind):
        self._predefinicoes[ind] = self._estacao
    
    def irParaPredefinicao(self, ind):
        self._estacao = self._predefinicoes[ind]
    
    def aumentarVolume(self):
        self._volume = self._volume + 1
    
    def diminuirVolume(self):
        self._volume = self._volume - 1
    
    def aumentarEstacao(self):
        self._estacao = self._estacao + .2
    
    def diminuirEstacao(self):
        self._estacao = self._estacao - .2

# Teste
r = Radio()
r.ligarDesligar()
r.aumentarVolume()
r.aumentarEstacao()
r.setPredefinicao(0)
r.irParaPredefinicao(0)
print(r._estacao)
