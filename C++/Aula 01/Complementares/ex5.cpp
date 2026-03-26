#include <iostream>
#include <string>

class Television{
    private:
        bool powerOn;
        bool muted;
        int volume;
        int channel;
        int prevChannel;

    public:
        //construtor
        Television(){
            powerOn = false;
            muted = false;
            volume = 10;
            channel = 2;
            prevChannel = 2;
        }

        bool togglePower(){
            powerOn = !powerOn;
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

    std::cout << tv.getStatus() << std::endl; 
    tv.togglePower();
    std::cout << tv.getStatus() << std::endl; 
    tv.volumeUp();
    std::cout << tv.getStatus() << std::endl; 
    tv.setChannel(5);
    std::cout << tv.getStatus() << std::endl; 
    tv.jumpPrevChannel();
    std::cout << tv.getStatus() << std::endl; 
    
    return 0;
}