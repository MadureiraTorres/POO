#3. Um cofre eletrônico guarda itens e só permite acesso mediante a combinação correta.
#Além disso, o cofre bloqueia permanentemente após três tentativas erradas seguidas — uma
#medida de segurança contra força bruta. Implemente versões em Python e C++ para uma
#classe Cofre com as seguintes características.
#• Atributos privados:
#– combinacao: string definida na criação do objeto,
#– conteudo: lista de itens guardados, inicia vazia,
#– aberto: booleano,
#– tentativas_erradas: contador, inicia em zero, e
#– bloqueado: booleano, inicia como falso.
#• Métodos públicos:
#– abrir(combinacao) verifica a combinação — se correta, abre o cofre e zera o
#contador de erros; se errada, incrementa o contador e bloqueia após três falhas;
#– fechar() fecha o cofre se estiver aberto;
#– guardar(item) adiciona um item ao conteúdo — só funciona com o cofre aberto;
#– retirar(item) remove um item — só funciona com o cofre aberto;
#– listar_conteudo() exibe os itens — só funciona com o cofre aberto;
#– esta_bloqueado() retorna se o cofre está bloqueado (único jeito de o código
#externo saber disso).
#• Métodos privados:
#– verificar_acesso() checa se o cofre está aberto e não bloqueado — chamado
#por guardar, retirar;
#– listar_conteudo para evitar repetição.
#– Adicione um método resetar_bloqueio(codigo_master) que aceita uma senha
#mestra diferente da combinação normal, e só então desbloqueia o cofre e zera as
#tentativas — simulando a intervenção de um técnico.
#• Principal restrição: o código externo nunca acessa conteudo, combinacao ou aberto
#diretamente.

class Cofre:    
    def __init__(self, combinacao, codigo_master="ADMIN123"):
        self.__combinacao = combinacao
        self.__codigo_master = codigo_master
        self.__conteudo = []
        self.__aberto = False
        self.__tentativas_erradas = 0
        self.__bloqueado = False

    def abrir(self, combinacao):
        if self.__bloqueado:
            print("Cofre bloqueado permanentemente. Chame um técnico.")
            return

        if combinacao == self.__combinacao:
            self.__aberto = True
            self.__tentativas_erradas = 0
            print("Cofre aberto com sucesso.")
        else:
            self.__tentativas_erradas += 1
            print(f"Combinação incorreta! Tentativa {self.__tentativas_erradas} de 3.")
            if self.__tentativas_erradas >= 3:
                self.__bloqueado = True
                print("ALERTA: Cofre bloqueado por excesso de tentativas.")

    def fechar(self):
        if self.__aberto:
            self.__aberto = False
            print("Cofre fechado.")

    def guardar(self, item):
        if self.__verificar_acesso():
            self.__conteudo.append(item)
            print(f"Item '{item}' guardado.")

    def retirar(self, item):
        if self.__verificar_acesso():
            if item in self.__conteudo:
                self.__conteudo.remove(item)
                print(f"Item '{item}' retirado.")
            else:
                print(f"Item '{item}' não encontrado no cofre.")

    def listar_conteudo(self):
        if self.__verificar_acesso():
            if not self.__conteudo:
                print("O cofre está vazio.")
            else:
                print("Conteúdo do cofre:", ", ".join(self.__conteudo))

    def esta_bloqueado(self):
        return self.__bloqueado

    def resetar_bloqueio(self, codigo_master):
        if codigo_master == self.__codigo_master:
            self.__bloqueado = False
            self.__tentativas_erradas = 0
            print("Bloqueio redefinido. Cofre desbloqueado.")
        else:
            print("Senha incorreta. Bloqueio não redefinido.")

    def __verificar_acesso(self):
        if not self.__aberto:
            print("O cofre está fechado. Abrir antes de acessar.")
            return False
        if self.__bloqueado:
            print("O cofre está bloqueado. Chame um técnico.")
            return False
        return True

if __name__ == "__main__":
    cofre = Cofre("1234")
    cofre.abrir("1234")
    cofre.guardar("Chave f5")
    