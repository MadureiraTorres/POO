#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;

class NomeInvalidoException : public exception{
    public:
        const char* what() const noexcept override{
            return "\nNome inválido!\n";
        }
};

class IdadeInvalidaException : public exception{
    public:
        const char* what() const noexcept override{
            return "\nIdade inválida\n";
        }
};

class SemDonoException : public exception{
    public:
        const char* what() const noexcept override{
            return "\nO animal deve ter um dono!\n";
        }
};

class Animal{
    private:
        string nome;
        string nomeDono;
        int idade;

    public:
        void setNome(string name){
            if(name.empty()){
                throw NomeInvalidoException();
            }
            
            this->nome = name;
        }

        void setIdade(int age){
            if(age < 0 || age > 50){
                throw IdadeInvalidaException();
            }

            this->idade = age;
        }

        void setDono(string ownerName){
            if(ownerName.length() < 3){
                throw NomeInvalidoException();
            }

            this->nomeDono = ownerName;
        }

        virtual void emitirSom() const = 0;

        virtual string descricao() const {
            return "Animal: " + nome + ", Dono: " + nomeDono + ", Idade: " + to_string(idade);
        }
        

};

class Cachorro : public Animal{
    public:
        void emitirSom() const override{
            cout << "Au au!" << endl;
        }

        string descricao() const override{
            return "Cachorro: " + Animal::descricao();
        }
};

class Gato : public Animal{
    public:
        void emitirSom() const override{
            cout << "Miau!" << endl;
        }

        string descricao() const override{
            return "Gato: " + Animal::descricao();
        }
};

class Papagaio : public Animal{
    private:
        string frase;

    public:
        string descricao() const override{
            return "Papagaio: " + Animal::descricao();
        }

        void aprenderFrase(string palavra){
            if(palavra.empty()){
                throw NomeInvalidoException();
            }

            this->frase = palavra;
        }

        string fraseAprendida(string palavra){
            if(palavra.empty()){
                throw NomeInvalidoException();
            }

            return "O papagaio aprendeu a dizer: " + palavra;
        }

        void emitirSom() const override{
            if(frase.empty()){
                cout << "..." << endl;
            } else{
                cout << "O papagaio diz: " << frase << endl;
            }
        }
};

int main(){
    vector<Animal*> animais;
    

    return 0;
}