#include <iostream>
#include <string>

typedef struct Node{
    int channel;
    struct Node* next;
    Node(int c) : channel(c), next(nullptr) {}
};

class Television{
    private:
        bool powerOn;
        bool muted;
        int volume;
        int channel;
        int prevChannel;
        Node* topFavourite;
        int favouriteCount;

    public:
        //construtor
        Television(){
            powerOn = false;
            muted = false;
            volume = 10;
            channel = 2;
            prevChannel = 2;
            topFavourite = nullptr;
            favouriteCount = 0;
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

        void addToFavourites(int n){
            Node* newNode = new Node(n);
            newNode->next = topFavourite;
            topFavourite = newNode;
            favouriteCount++;

        }

        int removeFromFavourites(){
            if(favouriteCount == 0){
                return -1; 
            }
            int removedChannel = topFavourite->channel;
            Node* temp = topFavourite;
            topFavourite = topFavourite->next;
            delete temp;
            favouriteCount--;
            return removedChannel;
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
    
    return 0;
}