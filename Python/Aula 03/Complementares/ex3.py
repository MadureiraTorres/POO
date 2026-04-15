class No:
    def __init__(self, dado):
        self.dado = dado
        self.proximo = None

    def __del__(self):
        if self.proximo is not None:
            del self.proximo

class Lista:
    def __init__(self):
        self.cabeca = None

    @classmethod
    def criar_copia(cls, outra_lista):
        nova_lista = cls()
        if outra_lista.cabeca is None:
            return nova_lista
        
        nova_lista.cabeca = No(outra_lista.cabeca.dado)
        atual_orig = outra_lista.cabeca.proximo
        atual_novo = nova_lista.cabeca
        
        while atual_orig is not None:
            atual_novo.proximo = No(atual_orig.dado)
            atual_novo = atual_novo.proximo
            atual_orig = atual_orig.proximo
            
        return nova_lista

    def inserir(self, dado):
        novo = No(dado)
        novo.proximo = self.cabeca
        self.cabeca = novo

    def __del__(self):
        if self.cabeca is not None:
            del self.cabeca

if __name__ == "__main__":

    minha_lista = Lista()
    minha_lista.inserir(10)
    minha_lista.inserir(20)
    print("Lista criada. Ao finalizar, o destrutor limpará os nós.")