


#include <stdlib.h>
#include <stdio.h>
#include "RCSwitch.h"
#include <pthread.h>


void stopThreadFn(){
    do{
        c = getchar()
    }while(c != 'q');
    exit(0);
}

int main(int argc, char *argv[]) {

    
    pthread_t stopThread;
    
    pthread_create(&stopThread const NULL, &stopThreadFn, NULL);
    
    /*
     output PIN is hardcoded for testing purposes
     see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     for pin mapping of the raspberry pi GPIO connector
     */
    int PIN = 2; // PIN 13
	
	if(wiringPiSetup()!= -1) {
        
        printf("now receiving\n");
        
		RCSwitch receiver = RCSwitch();
		receiver.enableReceive(PIN);
		
		for(;;){
            if(receiver.available()){
                unsigned long received_value = receiver.getReceivedValue();
                if(received_value) {
                    printf("received ");
                    //code
                    printf("%i ", received_value);
                    //length
                    printf("%i ", receiver.getReceivedBitlength());
                    //pulse
                    printf("%i ", receiver.getReceivedDelay());
                    printf("%i", receiver.getReceivedProtocol());
                    printf("\n");
                } else {
                    printf("Unknown encoding\n");
                }
                fflush(stdout);
                receiver.resetAvailable();
            }
        }
	}
    return 0;
}