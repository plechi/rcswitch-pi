


#include <stdlib.h>
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include "RCSwitch.h"

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
		receiver.enableReceive(PIN);
		
		while(1) {
			if(receiver.available()) {
				int received_value = receiver.getReceivedValue();
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
			}else{
                //sched_yield();
                sleep(1);
            }
		}
		
	}
    return 0;
}