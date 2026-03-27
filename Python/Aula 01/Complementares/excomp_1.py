#1. Considere o seguinte código para a definição de um Widget:
#def Widget:
#def Widget(self):
#self._msg = "Hello, I'm a widget!"
#def replace(self)
#index = self.index('w')
#self._msg[index] = 'g'
#def __str__(self):
#print 'My string is: ' + self._msg
#Existem diferentes erros no programa acima (uma combinação de erros sintáticos e semânticos). Identifique e corrija pelo menos 4 dos erros.

class Widget:
    def __init__(self):
        self._msg = "Hello, I'm a widget!"
    
    def replace(self):
        index = self._msg.find('w')
        if index != -1:
            self._msg = self._msg[:index] + 'g' + self._msg[index+1:]
    
    def __str__(self):
        return 'My string is: ' + self._msg

# Teste
w = Widget()
w.replace()
print(w)