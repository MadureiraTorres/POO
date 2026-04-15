class Gerenciador:
    lista_processos = []

    @classmethod
    def registrar(cls, processo):
        cls.lista_processos.append(processo)

    @classmethod
    def remover(cls, processo):
        if processo in cls.lista_processos:
            cls.lista_processos.remove(processo)

    @classmethod
    def listar_ativos(cls):
        nomes = [p.nome for p in cls.lista_processos]
        print(f"Processos Ativos: {nomes}")

class Processo:
    def __init__(self, nome):
        self.nome = nome
        Gerenciador.registrar(self)

    def __del__(self):
        Gerenciador.remover(self)

def rotina_temporaria():
    p2 = Processo("PROCESSO_TEMP_2")
    p3 = Processo("PROCESSO_TEMP_3")
    print("Dentro da rotina:")
    Gerenciador.listar_ativos()
    print("Encerrando rotina...")

if __name__ == "__main__":
    p1 = Processo("PROCESSO_MAIN_1")
    
    rotina_temporaria()
    
    print("Fora da rotina:")
    Gerenciador.listar_ativos()