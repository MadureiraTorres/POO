#Implemente uma classe de ImagemDigital em Python, 
# adicionando atributos, métodos e faça testes de atribuição e 
# acesso de valores em uma função principal.

class ImagemDigital:
    def __init__(self):
        self._largura = 0
        self._altura = 0
        self._nome = ""

    @property
    def largura(self):
        return self._largura

    @largura.setter
    def largura(self, valor):
        self._largura = valor

    @property
    def altura(self):
        return self._altura

    @altura.setter
    def altura(self, valor):
        self._altura = valor

    @property
    def nome(self):
        return self._nome

    @nome.setter
    def nome(self, valor):
        self._nome = valor

if __name__ == "__main__":
    foto = ImagemDigital()
    print(type(foto))