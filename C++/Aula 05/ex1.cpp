#include <iostream>
#include <string>
#include <stdexcept>
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
        

};

int main(){
    return 0;
}