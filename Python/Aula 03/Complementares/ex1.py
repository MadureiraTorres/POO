class Livro:
    def __init__(self, titulo, autor, ano=None):
        self.titulo = titulo
        self.autor = autor
        self.ano = ano
        print(f"Livro '{self.titulo}' alocado.")

    def __del__(self):
        print(f"Livro '{self.titulo}' destruído (desalocado).")

def testar_livros():
    print("--- Início do Escopo da Função ---")
    lista_livros = [
        Livro("Estrutura de Dados", "Autor A"),
        Livro("Sistemas Operacionais", "Autor B", 2021)
    ]
    print("--- Fim do Escopo da Função ---")

if __name__ == "__main__":
    testar_livros()
    print("O programa principal foi finalizado.")
