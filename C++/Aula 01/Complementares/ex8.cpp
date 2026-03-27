#include <iostream>
#include <string>

struct Node{
    int channel;
    Node* next;
    Node* prev;

    Node(int ch) : channel(ch), next(nullptr), prev(nullptr) {}
};

class Television{
    private:
        bool powerOn;
        bool muted;
        int volume;
        int channel;
        int prevChannel;
        Node* headFavorite;   
        Node* currentFavorite;  
        int favoriteCount;

    public:
        //construtor
        Television(){
            powerOn = false;
            muted = false;
            volume = 10;
            channel = 2;
            prevChannel = 2;
            headFavorite = nullptr;
            currentFavorite = nullptr;
            favoriteCount = 0;
        }

        bool togglePower(){
            powerOn = !powerOn;

            if(powerOn){
                muted = false;
            }
            return powerOn;
        }

        bool toggleMute(){
            if(powerOn){
                muted = !muted;
            }
            return muted;
        }

        int volumeUp(){
            if(powerOn && !muted && volume < 100){
                volume++;
            }
            return volume;
        }

        int channelUp(){
            if(powerOn){
                if(channel == 99){
                    channel = 2;
                } else {
                    channel++;
                }
                prevChannel = channel;
                channel++;
            }
            return channel;
        }

        int setChannel(int n){
            if(powerOn && n >= 2 && n <= 99){
                prevChannel = channel;
                channel = n;
            }
            return channel;
        }

        int jumpPrevChannel(){
            if(powerOn){
                int temp = channel;
                channel = prevChannel;
                prevChannel = temp;
            }
            return channel;
        }

        void factoryReset(){
            muted = false;
            volume = 10;
            channel = 2;
            prevChannel = 2;
        }

        void addFavorite(int channel) {
            Node* newNode = new Node(channel);

            if (headFavorite == nullptr){
                headFavorite = newNode;
                currentFavorite = newNode;
                favoriteCount++;
                return;
            }

            Node* temp = headFavorite;

            while (temp != nullptr){
                if (temp->channel == channel) return; 
                temp = temp->next;
            }

            temp = headFavorite;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            
            temp->next = newNode;
            newNode->prev = temp;
            favoriteCount++;
        }

        void removeFavorite(int channel){
            Node* temp = headFavorite;

            while (temp != nullptr) {
                if (temp->channel == channel) {
                    if (temp->prev) temp->prev->next = temp->next;
                    else headFavorite = temp->next; 

                    if (temp->next) temp->next->prev = temp->prev;

                    if (currentFavorite == temp)
                    currentFavorite = temp->next ? temp->next : temp->prev;

                    delete temp;
                    favoriteCount--;
                    return;
            }

            temp = temp->next;
            }
        }

        bool goToFavorite(int channel){
            Node* temp = headFavorite;
            while (temp != nullptr) {
                if (temp->channel == channel) {
                    currentFavorite = temp;
                    if (powerOn) this->channel = channel;
                    return true;
                }
            temp = temp->next;
            }
            return false; // não encontrado
        }


        std::string getStatus(){
            std::string status = "Power: " + std::string(powerOn ? "On" : "Off") + "\n";
            status += "Muted: " + std::string(muted ? "Yes" : "No") + "\n";
            status += "Volume: " + std::to_string(volume) + "\n";
            status += "Channel: " + std::to_string(channel) + "\n";
            return status;
        }
        
};

int main(){
    Television tv;

    std::cout << "Status inicial da TV:" << std::endl;
    std::cout << tv.getStatus() << std::endl; 

    tv.togglePower();
    std::cout << "Após ligar:" << std::endl;
    std::cout << tv.getStatus() << std::endl; 

    tv.volumeUp();
    std::cout << "Após aumentar o volume:" << std::endl;
    std::cout << tv.getStatus() << std::endl;

    tv.setChannel(5);
    std::cout << "Após mudar para o canal 5:" << std::endl;
    std::cout << tv.getStatus() << std::endl; 

    tv.jumpPrevChannel();
    std::cout << "Após voltar para o canal anterior:" << std::endl;
    std::cout << tv.getStatus() << std::endl; 

    tv.toggleMute();
    std::cout << "Após ativar o mudo:" << std::endl;
    std::cout << tv.getStatus() << std::endl;

    tv.togglePower();
    std::cout << "Após desligar:" << std::endl;
    std::cout << tv.getStatus() << std::endl;

    tv.togglePower();
    std::cout << "Após ligar novamente:" << std::endl;
    std::cout << tv.getStatus() << std::endl;

    tv.factoryReset();
    std::cout << "Após resetar para as configurações de fábrica:" << std::endl;
    std::cout << tv.getStatus() << std::endl;

    tv.addFavorite(11);
    tv.addFavorite(22);
    tv.addFavorite(45);

    tv.goToFavorite(45);

    tv.removeFavorite(22);
    
    return 0;
}