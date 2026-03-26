#include  <iostream>
#include  <string>

class Widget{
    private:
        std::string msg;

    public:
        //construtor da classe
        Widget(){
            msg = "Hello, I'm a widget!";
        }

        void replace(){
            size_t index = msg.find("w");
            if (index != std::string::npos) {
                msg[index] = 'g';
            }
        }

        std::string getMsg(){
            return msg;
        }
};

int main(){
    Widget w;

    std::cout << w.getMsg() << std::endl; 
    w.replace();
    std::cout << w.getMsg() << std::endl; 
    
    return 0;
}