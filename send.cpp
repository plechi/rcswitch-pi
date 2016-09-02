/*
 Usage: ./send <systemCode> <unitCode> <command>
 Command is 0 for OFF and 1 for ON
 */

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    
    /*
     output PIN is hardcoded for testing purposes
     see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     for pin mapping of the raspberry pi GPIO connector
     */
    int PIN = 0;
    
    unsigned long code = atol(argv[1]);
    unsigned int length = atoi(argv[2]);
    int pulseLength = atoi(argv[3]);
    int protocol = = atoi(argv[4]);
    
    if (wiringPiSetup () == -1) return 1;
    
	RCSwitch mySwitch = RCSwitch();
	mySwitch.enableTransmit(PIN);
    
    mySwitch.setProtocol(protocol, pulseLength);
    mySwitch.send(code, length);
    
	return 0;
}
