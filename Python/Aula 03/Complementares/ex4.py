class ObjetoPool:
    def __init__(self):
        self.ativo = False
        self.dado = None

    def construir(self, dado):
        self.ativo = True
        self.dado = dado

    def limpar(self):
        if self.ativo:
            self.ativo = False
            self.dado = None

class PoolMemoria:
    def __init__(self, tamanho):
        self.bloco = [ObjetoPool() for _ in range(tamanho)]
        
    def obter_objeto(self, dado):
        for obj in self.bloco:
            if not obj.ativo:
                obj.construir(dado)
                return obj
        raise MemoryError("Pool de memória esgotado")

    def __del__(self):
        for obj in self.bloco:
            obj.limpar()
        print("Bloco de memória do Pool liberado.")

if __name__ == "__main__":
    pool = PoolMemoria(5)
    obj1 = pool.obter_objeto("Dado A")
    obj2 = pool.obter_objeto("Dado B")
    print("Objetos obtidos do Pool.")