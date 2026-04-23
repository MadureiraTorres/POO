class Livro:
    # Atributo classe para controlar a chave incremental
    _proxima_chave = 1 

    def __init__(self, titulo: str, autor: str, ano: int):
        # A chave recebe o valor atual e incrementa para o próximo cadastrado
        self.chave = Livro._proxima_chave
        Livro._proxima_chave += 1
        
        self.titulo = titulo
        self.autor = autor
        self.ano = ano

    def __del__(self):
        # Destrutor, indica que o objeto foi desalocado
        print(f"[Destrutor] O objeto Livro '{self.titulo}' (Chave: {self.chave}) foi desalocado da memória.")

    def exibir_informacoes(self):
        print(f"[Livro Base] Chave: {self.chave} | Título: {self.titulo} | Autor: {self.autor} | Ano: {self.ano}")


class LivroFisico(Livro):
    def __init__(self, titulo: str, autor: str, ano: int, numero_paginas: int):
        # Utiliza o construtor da classe base (super)
        super().__init__(titulo, autor, ano)
        self.numero_paginas = numero_paginas

    def exibir_informacoes(self):
        # Sobrescreve método (Polimorfismo) para exibir informações completas
        print(f"[Livro Físico] Chave: {self.chave} | Título: {self.titulo} | Autor: {self.autor} | Ano: {self.ano} | Páginas: {self.numero_paginas}")


class LivroDigital(Livro):
    def __init__(self, titulo: str, autor: str, ano: int, tamanho_arquivo: float, formato: str):
        # Utiliza o construtor da classe base (super)
        super().__init__(titulo, autor, ano)
        self.tamanho_arquivo = tamanho_arquivo
        self.formato = formato

    def exibir_informacoes(self):
        # Sobrescreve método (Polimorfismo) para exibir informações completas
        print(f"[Livro Digital] Chave: {self.chave} | Título: {self.titulo} | Autor: {self.autor} | Ano: {self.ano} | Tamanho: {self.tamanho_arquivo} MB | Formato: {self.formato}")


class LivroAcademicoDigital(LivroDigital):
    def __init__(self, titulo: str, autor: str, ano: int, tamanho_arquivo: float, formato: str, area: str, instituicao: str):
        # Utiliza o construtor da classe LivroDigital que repassa classe Livro
        super().__init__(titulo, autor, ano, tamanho_arquivo, formato)
        self.area = area
        self.instituicao = instituicao

    def exibir_informacoes(self):
        # Sobrescreve método (Polimorfismo) para exibir informações completas
        print(f"[Livro Acadêmico Digital] Chave: {self.chave} | Título: {self.titulo} | Autor: {self.autor} | Ano: {self.ano} | Tamanho: {self.tamanho_arquivo} MB | Formato: {self.formato} | Área: {self.area} | Instituição: {self.instituicao}")


if __name__ == '__main__':
    print("INICIANDO SISTEMA DE LIVROS\n")

    # Cria uma lista contendo livros de diferentes tipos para demonstrar o Polimorfismo
    colecao_livros = [
        Livro("Dom Casmurro", "Machado de Assis", 1899),
        LivroFisico("O Senhor dos Anéis", "J.R.R. Tolkien", 1954, 1200),
        LivroDigital("Python Fluente", "Luciano Ramalho", 2015, 15.5, "PDF"),
        LivroAcademicoDigital("Estrutura de Dados e Algoritmos", "Thomas H. Cormen", 2009, 25.0, "EPUB", "Ciência da Computação", "MIT")
    ]

    # Percorre a coleção e exibe informações
    print("EXIBINDO INFORMAÇÕES DOS LIVROS")
    for livro in colecao_livros:
        livro.exibir_informacoes()
        
    print("\nFIM DO PROGRAMA (Iniciando desalocação)")