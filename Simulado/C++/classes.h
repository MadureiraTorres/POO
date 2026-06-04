#ifndef CLASSES_H
#define CLASSES_H
////////////////////////////
#include <ctime>
#include <string>
#include <vector>
using namespace std;

//classe usuario (abstrata)
/*
classe: usuário (abstrata)
abstração base para as pessoas vinculadas ao sistema.
atributos sugeridos: id: long, nome: string, matricula: string,
email: string, ativo: boolean.
métodos chave: autenticar(), podeRetirarChave() (abstrato).
*/
class Usuario{
    private:
        long id;

    protected:
        string nome;
        string matricula;
        string email;
        bool ativo;

    public:
        bool autenticar(){};
        virtual bool podeRetirarChave() = 0;
        virtual ~Usuario(){};
};

//classes derivadas de usuário
/*
classes: professor/tecnico/administrador
especializações da classe usuário.
nota de implementação: devem implementar o método polimórfico de 
premissão ou prazos de devolução diferenciados (ex: professores
possuem prazo de 24h, tecnicos possuem prazo de 8h). o adminsitrador 
possui métodos de gestão como cadastrarChave() e gerarRelatorios().
*/
//classe derivada - professor
class Professor : public Usuario{
    public:
        bool podeRetirarChave() override{
            //pode retirar a chave por 24 horas
            return true;
        }
};

//classe derivada - tecnico
class Tecnico : public Usuario{
    public:
        bool podeRetirarChave() override{
            //pode retirar a chave por 8 horas
            return true;
        }
};

//classe derivada - administrador
class Administrador : public Usuario{
    public:
        bool podeRetirarChave() override{
            //administrador não retira chaves
            return false;
        }

        void cadastrarChave(){};
        void gerarRelatorios(){};
};

//classe emprestimo
/*
classe: emprestimo
classe associativa que materializa o evento de posse temporária de um
item
atributos sugeridos: id: long, usuario: Usuario, chave: Chave, 
dataRetirada: LocalDateTime, dataPrevista: LocalDateTime, 
dataDevolucaoEfetiva: LocalDateTime, justificativa: string.
metodos chave: encerrarEmprestimo(), verificarAtraso(): boolean.
*/
class Emprestimo{
    private:
        long id;
        Time dataRetirada;
        Time dataPrevista;
        Time devolucao;
        string justificativa;
    
    public:
        void registrarEmprestimo();
        bool estaAtrasado();
};

//classe chave
/* 
classe: chave
objeto físico monitorado pelo sistema.
atributos sugeridos: id: long, codigo: string, status: StatusChave
(Enum), ambiente: Ambiente.
onde StatusChave assume valores como DISPONIVEL, EMPRESTADA, ATRASADA.
*/
class Chave{
    private:
        enum StatusChave { DISPONIVEL, EMPRESTADA, ATRASADA };
        long id;
        string codigo;
        StatusChave status;
    
    public:
        bool estaDisponivel(){
            return status == DISPONIVEL;
        }
    
        void status(StatusChave novoStatus){
            status = novoStatus;
        }
};

//classe ambiente
/*
classe: ambiente
representa a infraestrutura física da instituição
atributos sugeridos: id: long, nome: string (ex: "Lab de Redes"), 
bloco: string, descricaoa: string.
*/
class Ambiente{
    private:
        long id;
        string nome;
        string bloco;
        string descricao;
};

//classe gerenciador de chaves
/*
classe/camada: gerenciador de chaves (controlador)
centrealizador das regras de negócio do sistema, concentrando coleções
de dados (Lists/Maps) e os métodos de orquestração como 
realizarEmprestimo(usuario, chave) e registrarDevolucao(chave).
*/
class GerenciadorChaves{
    private:
        vector<Usuario*> usuarios; 
        vector<Chave> chaves;
        vector<Emprestimo> emprestimos;
    public:
        void realizarEmprestimo(Usuario* usuario, Chave& chave){};
        void registrarDevolucao(Chave& chave){};
};

class Time{

    public:
        Time(int = 0, int = 0, int = 0); 
        Time(const Time&);

        void setTime(int, int, int);     
        void setHour(int);               
        void setMinute(int);             
        void setSecond(int);           

        int getHour();
        int getMinute();
        int getSecond();

        void printUniversal(); 
        void printStandard();           
    private:
        int hour;  
        int minute; 
        int second; 
};

#endif