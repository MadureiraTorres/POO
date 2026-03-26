def Widget(): #erro 1, falta o parênteses para definir a classe

    #construtor da classe
    def __init__(self): #erro 2, o método construtor deve ser __init__
        self._msg = "Hello, I'm a widget!"
    
    #def replace(self): 
    #    index = self.index('w')
    #    self._msg[index] = 'g' 

    def __str__(self): 
        print('My string is: ' + self._msg) #erro 3, falta os parênteses para a função print 