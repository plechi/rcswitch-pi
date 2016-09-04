


#include <stdlib.h>
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include "RCSwitch.h"

void onReceive(RCSwitch switch){
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
    receiver.resetAvailable();
}

int main(int argc, char *argv[]) {

    /*
     output PIN is hardcoded for testing purposes
     see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     for pin mapping of the raspberry pi GPIO connector
     */
    int PIN = 2; // PIN 13
	
	if(wiringPiSetup()!= -1) {
        
        printf("now receiving\n");
        
		RCSwitch receiver = RCSwitch();
		receiver.enableReceive(PIN, &onReceive);
        
        while(1){
            sched_yield();
        }
		
	}
    return 0;
}