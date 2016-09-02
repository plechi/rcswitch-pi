#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    /*
     output PIN is hardcoded for testing purposes
     see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     for pin mapping of the raspberry pi GPIO connector
     */
    int PIN = 2; // PIN 13
	
	if(wiringPiSetup()!= -1) {
        
		RCSwitch receiver = RCSwitch();
		receiver.enableReceive(PIN);
		
		while(1) {
			if(receiver.available()) {
				int received_value = receiver.getReceivedValue();
				if(received_value) {
					printf("Received ");
					printf("%i", received_value);
					printf(" / ");
					printf("%i", receiver.getReceivedBitlength());
					printf(" bit ");
					printf("Protocol: ");
					printf("%i", receiver.getReceivedProtocol());
					printf("\n");
                    printf("pulse: ");
					printf("%i", receiver.getReceivedDelay());
					printf("\n");
				} else {
					printf("Unknown encoding\n");
				}
				receiver.resetAvailable();
			}
		}
		
	}
    return 0;
}