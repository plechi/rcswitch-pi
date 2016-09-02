
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
     
    if (wiringPiSetup () == -1) return 1;
    
	RCSwitch mySwitch = RCSwitch();
	mySwitch.enableTransmit(PIN);
    
    mySwitch.sendTriState(argv[1])
    
	return 0;
}
