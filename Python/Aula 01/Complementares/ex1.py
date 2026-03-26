class Widget:
    def __init__(self):
        self._msg = "Hello, I'm a widget!"

    def replace(self):
        index = self._msg.index('w')
        msg_list = list(self._msg)
        msg_list[index] = 'g'
        self._msg = ''.join(msg_list)

    def __str__(self):
        return 'My string is: ' + self._msg
    
#erros:
#Declaração de classe incorreta — def em vez de class
#Nome do construtor incorreto — deve ser __init__, não o nome da classe
#String é imutável — não é possível modificar um caractere diretamente pelo índice
#Dois erros no __str__ — print sem parênteses (sintaxe Python 2) e nome do atributo errado (_ms em vez de _msg). 
# Além dissoS, __str__ deve retornar a string, não imprimi-la.