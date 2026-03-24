#Exercicio 1:  Implemente uma classe de ImagemDigital em Python, adicionando atributos, métodos e faça testes de atribuição e acesso de valores em uma função principal.
#Exercicio 2: Adicione novos métodos na classe ImagemDigital

class ImagemDigital:
    def __init__(self, largura, altura, nome_arquivo):
        self.largura = largura
        self.altura = altura
        self.nome_arquivo = nome_arquivo

    def redimensionar(self, nova_largura, nova_altura):
        self.largura = nova_largura
        self.altura = nova_altura

    def get_dimensoes(self):
        return self.largura, self.altura

    def get_nome_arquivo(self):
        return self.nome_arquivo

# Função principal

if __name__ == "__main__":
    # Criando uma imagem digital
    imagem = ImagemDigital(1920, 1080, "imagem.jpg")

    # Acessando os atributos
    print("Largura:", imagem.largura)
    print("Altura:", imagem.altura)
    print("Nome do arquivo:", imagem.nome_arquivo)

    # Redimensionando a imagem
    imagem.redimensionar(800, 600)

    # Acessando os atributos após o redimensionamento
    print("Nova largura:", imagem.largura)
    print("Nova altura:", imagem.altura)

    # Obtendo as dimensões
    dimensoes = imagem.get_dimensoes()
    print("Dimensões:", dimensoes)

    # Obtendo o nome do arquivo
    nome_arquivo = imagem.get_nome_arquivo()
    print("Nome do arquivo:", nome_arquivo)
