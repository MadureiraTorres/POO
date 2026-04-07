#Exercicio 2: Crie uma classe Matriz que aloca dinamicamente um array bidimensional de inteiros no construtor, recebendo linhas e colunas como parâmetros. Implemente
#o destrutor para liberar a memória alocada. Em seguida, implemente o construtor de cópia para que duas matrizes não compartilhem o mesmo bloco de memória (cópia profunda). 
#Demonstre na função main que modificar uma cópia não afeta o original.

import copy

class Matriz:
    def __init__(self, linhas, colunas, valor_inicial=0):
        self.linhas = linhas
        self.colunas = colunas
        
        # Alocação dinâmica de uma lista de que contem listas (matriz bidimensional)
        self.dados = [[valor_inicial for _ in range(colunas)] for _ in range(linhas)]
        print(f"Matriz {self.linhas}x{self.colunas} alocada na memória.")

    def __del__(self):
        "Destrutor: Em Python, limpa as referências para o GC coletar."
        print(f"Destrutor chamado: Liberando memória da matriz {self.linhas}x{self.colunas}.")
        self.dados = None

    def construtor_de_copia(self):
        "Implementa a lógica de cópia profunda (Deep Copy)."
        
        # Nova instância
        nova_matriz = Matriz(self.linhas, self.colunas)
        
        # Copiamos os valores um a um para garantir blocos de memória distintos
        for i in range(self.linhas):
            for j in range(self.colunas):
                nova_matriz.dados[i][j] = self.dados[i][j]
        return nova_matriz

    def alterar_elemento(self, linha, coluna, novo_valor):
        if 0 <= linha < self.linhas and 0 <= coluna < self.colunas:
            self.dados[linha][coluna] = novo_valor

    def exibir(self, nome):
        print(f"Matriz {nome}:")
        for linha in self.dados:
            print(linha)
        print("-" * 20)

def main():
    # 1. Criar matriz original: 2x2
    print("Criando Original")
    original = Matriz(2, 2, valor_inicial=10)
    original.exibir("Original")

    # 2. Criar cópia profunda (não compartilham memória)
    print("Criando Cópia Profunda")
    copia = original.construtor_de_copia()
    
    # 3. Modificar a cópia
    print("Modificando a Cópia (Cópia[0][0] = 99)")
    copia.alterar_elemento(0, 0, 99)

    # 4. Demonstrar que o original permanece intacto
    original.exibir("Original (após mudar cópia)")
    copia.exibir("Cópia (após mudança)")

if __name__ == "__main__":
    main()
    print("Fim.")