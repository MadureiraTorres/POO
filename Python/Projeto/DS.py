# Projeto: Classe de Jogador de RPG inspirado em DS
# nome: Nome do Jogador
# classe: Classe inicial (influencia apenas os atributos iniciais e o equipamento)
# vida: Atributo HP (pontos de vida), aumenta principalmente com Vitalidade
# stamina: Barra de energia; em DS1, ela aumenta exclusivamente com Fortitude
# nivel: Nível de Alma (Soul Level); aumenta a cada ponto gasto em atributos
# almas: Moeda principal para comércio e para subir de nível nos Bonfires
# vitalidade: Aumenta o HP máximo e a resistência física global
# conhecimento: Aumenta o número de slots (espaços) para equipar Magias, Milagres e Piromancias
# fortitude: Aumenta a Stamina, a Carga de Equipamento (Equip Load) e a Resistência a Sangramento
# forca: Requisito para armas pesadas; aumenta o dano de armas com escalonamento em Força
# destreza: Requisito para armas ágeis; aumenta o dano de armas "Dex" e reduz o tempo de cast de magias
# resistencia: Aumenta a defesa física e a resistência a Veneno (considerado o atributo menos útil do jogo)
# inteligencia: Requisito para usar Sorceries (Feitiçarias); aumenta o dano de catalisadores e armas mágicas
# fe: Requisito para usar Milagres; aumenta o poder de talismãs e armas divinas/ocultas

from abc import ABC, abstractmethod

# EXCEÇÕES CUSTOMIZADAS
class StaminaInsuficienteError(Exception):
    pass

class AlvoMortoError(Exception):
    pass

# HERANÇA
class Entidade:
    def __init__(self, nome, vida, stamina):
        self.__nome = nome
        self.__vida = vida
        self.__stamina = stamina

    def getNome(self):
        return self.__nome

    def getVida(self):
        return self.__vida

    def setVida(self, vida):
        self.__vida = vida

    def getStamina(self):
        return self.__stamina

    def setStamina(self, stamina):
        self.__stamina = stamina

    def estaVivo(self):
        return self.__vida > 0

    def receberDano(self, dano):
        if dano > 0:
            self.__vida -= dano
            if self.__vida < 0:
                self.__vida = 0
            print(f"{self.__nome} recebeu {dano} de dano! Vida restante: {self.__vida}")

    def atacar(self, alvo):
        pass


# POLIMORFISMO E HERANÇA
class Inimigo(Entidade):
    def __init__(self, nome, vida, stamina, danoBase):
        super().__init__(nome, vida, stamina)
        self.__danoBase = danoBase

    def atacar(self, alvo):
        if not alvo.estaVivo():
            raise AlvoMortoError(f"O alvo {alvo.getNome()} ja esta morto!")
        
        print(f"{self.getNome()} ataca {alvo.getNome()}!")
        alvo.receberDano(self.__danoBase)


class Jogador(Entidade):
    def __init__(self, nome, classe, vida, stamina, nivel, almas, vitalidade, conhecimento, fortitude, forca, destreza, resistencia, inteligencia, fe):
        super().__init__(nome, vida, stamina)
        self.__classe = classe
        self.__nivel = nivel                  
        self.__almas = almas                  
        self.__vitalidade = vitalidade        
        self.__conhecimento = conhecimento    
        self.__fortitude = fortitude          
        self.__forca = forca                  
        self.__destreza = destreza            
        self.__resistencia = resistencia      
        self.__inteligencia = inteligencia    
        self.__fe = fe                        

    def exibirStatus(self):
        print(f"Nome: {self.getNome()}")
        print(f"Classe: {self.__classe}")
        print(f"Nivel: {self.__nivel}")
        print(f"Vida: {self.getVida()}")
        print(f"Stamina: {self.getStamina()}")
        print(f"Almas: {self.__almas}")
        print(f"Vitalidade: {self.__vitalidade}")
        print(f"Conhecimento: {self.__conhecimento}")
        print(f"Fortitude: {self.__fortitude}")
        print(f"Forca: {self.__forca}")
        print(f"Destreza: {self.__destreza}")
        print(f"Resistencia: {self.__resistencia}")
        print(f"Inteligencia: {self.__inteligencia}")
        print(f"Fe: {self.__fe}")

    def curar(self, quantidade):
        if quantidade > 0 and self.estaVivo():
            novaVida = self.getVida() + quantidade
            self.setVida(novaVida)
            print(f"{self.getNome()} foi curado em {quantidade} pontos! Vida atual: {self.getVida()}")
            
    def consumirItem(self, item):
        # Verifica se o objeto passado realmente segue o contrato da interface
        if isinstance(item, IItemUsavel):
            print(f"\n{self.getNome()} está tentando usar um item...")
            item.usarItem(self) # Passa o próprio jogador como alvo
        else:
            print("Este objeto não é um item usável!")
            
# INTERFACES
class IItemUsavel(ABC):
    """Interface: Define o contrato para qualquer item que possa ser usado no jogo.
    Não possui lógica, apenas a assinatura do método."""
    @abstractmethod
    def usarItem(self, alvo):
        pass

# IMPLEMENTAÇÃO DA INTERFACE
class EstusFlask(IItemUsavel):
    def __init__(self, cargasIniciais, poderCura):
        self.__cargas = cargasIniciais
        self.__poderCura = poderCura

    def usarItem(self, alvo):
        if self.__cargas > 0:
            self.__cargas -= 1
            print(f"O item Frasco de Estus foi ativado!")
            alvo.curar(self.__poderCura)
            print(f"Cargas restantes de Estus: {self.__cargas}")
        else:
            print("Frasco de Estus vazio! Descanse em uma Bonfire.")


class Humanidade(IItemUsavel):
    def __init__(self):
        self.__curaTotal = 9999 # A humanidade cura todo o HP
        
    def usarItem(self, alvo):
        print(f"Humanidade esmagada! Recuperando toda a vida.")
        alvo.curar(self.__curaTotal)

# SISTEMA DE ATAQUE ESPECÍFICO DO JOGADOR
    def atacar(self, alvo):
        if not alvo.estaVivo():
            raise AlvoMortoError(f"O alvo {alvo.getNome()} ja esta morto!")
        
        custoStamina = 30
        staminaAtual = self.getStamina()
        
        if staminaAtual < custoStamina:
            raise StaminaInsuficienteError(f"{self.getNome()} nao tem stamina suficiente para atacar!")
        
        # Consome a stamina
        self.setStamina(staminaAtual - custoStamina)
        
        # O dano aumenta com base no atributo Força
        danoCalculado = self.__forca * 3
        
        print(f"{self.getNome()} ataca {alvo.getNome()}! (Stamina restante: {self.getStamina()})")
        alvo.receberDano(danoCalculado)


if __name__ == "__main__":
    # Criando um jogador
    jogador1 = Jogador(
        nome="Hargon",
        classe="Arqueiro",
        vida=100,
        stamina=100,
        nivel=10,
        almas=10,
        vitalidade=10,
        conhecimento=10,
        fortitude=10,
        forca=15,
        destreza=10,
        resistencia=10,
        inteligencia=10,
        fe=10
    )

    # Criando um inimigo para testar o sistema de ataque
    hollow = Inimigo(
        nome="Undead Hollow",
        vida=40,
        stamina=50,
        danoBase=15
    )

    # Instanciando os itens
    meuEstus = EstusFlask(cargasIniciais=3, poderCura=50)
    minhaHumanidade = Humanidade()

    print("\nTESTANDO ITENS")
    
    # O jogador toma dano para testar a cura
    jogador1.receberDano(80)
    
    # Jogador usa o Estus Flask (que implementa IItemUsavel)
    jogador1.consumirItem(meuEstus)
    
    # Jogador usa a Humanidade (que implementa a mesma interface, mas age diferente)
    jogador1.consumirItem(minhaHumanidade)

    jogador1.exibirStatus()
    print("\nINICIO DO COMBATE")

    try:
        # Jogador ataca
        jogador1.atacar(hollow)
        #print()
        
        # Inimigo ataca
        hollow.atacar(jogador1)
        #print()
        
        # Jogador ataca novamente
        jogador1.atacar(hollow)
        #print()
        
        # Jogador tenta atacar um alvo que já morreu
        jogador1.atacar(hollow)
        
    except StaminaInsuficienteError as e:
        print(f"AVISO DE COMBATE: {e}")
    except AlvoMortoError as e:
        print(f"AVISO DE COMBATE: {e}")

    print("FIM DO COMBATE")
    jogador1.curar(20)
