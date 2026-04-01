#1. Um termostato doméstico controla a temperatura de um ambiente. Por segurança, a
# -temperatura não pode ser definida livremente — ela só pode ser ajustada gradualmente, dentro de limites seguros. Implemente versões em Python e C++ para uma classe Termostato
# -com as seguintes características:
#• Atributos privados:
# -temperatura (inicia em 20°C);
# -e ligado (booleano, inicia desligado).
#Métodos públicos:
# -ligar() e desligar() alternam o estado do aparelho;
# -aumentar(graus) e diminuir(graus) só funcionam se o termostato estiver ligado
# -e só são permitidos se o resultado ficar entre 0°C e 40°C — caso contrário, exibe
# -uma mensagem de aviso;
# -exibir_estado() mostra se está ligado e a temperatura atual.
#• Métodos privados:
# -adicione um método privado validar_temperatura(valor) que centraliza a verificação dos limites e é chamado por aumentar e diminuir.
#• Principal restrição: nenhum código externo à classe pode ler ou alterar temperatura
# -diretamente. Toda interação passa pelos métodos públicos.

class Termostato:
    def __init__(self):
        self.__temperatura = 20
        self.__ligado = False
        
    def ligar(self):
        self.__ligado = True
        
    def desligar(self):
        self.__ligado = False

    def __validar_temperatura(self, valor):
        return 0 <= valor <= 40
        
    def aumentar(self,graus):
        if self.__ligado:
            if self.__validar_temperatura(self.__temperatura + graus):
                self.__temperatura += graus
            else:
                print("Aviso: Temperatura fora dos limites seguros (0°C a 40°C).")
    
    def diminuir(self,graus):
        if self.__ligado:
            if self.__validar_temperatura(self.__temperatura - graus):
                self.__temperatura -= graus
            else:
                print("Aviso: Temperatura fora dos limites seguros (0°C a 40°C).")

    def exibir_estado(self):
        if self.__ligado:
            print(f"Ligado | Temperatura atual: {self.__temperatura}°C")
        else:
            print(f"Desligado | Temperatura atual: {self.__temperatura}°C")
        
if __name__ == "__main__":
    termostato = Termostato()
    termostato.exibir_estado()
    termostato.ligar()
    termostato.aumentar(5)
    termostato.exibir_estado()
    termostato.desligar()
    termostato.exibir_estado()
        

        
        