#ifndef CHANGE
#define CHANGE INT_EDGE_BOTH
#endif

// necessary values to port rc-switch to the raspberry pi
#ifndef boolean
#define boolean int
#endif

#ifndef byte
#define byte char
#endif

// replace detachInterrupt() with a empty block
#define detachInterrupt(x) do { } while(0)

// map attachInterrupt() to wiringPi equivalent
#define attachInterrupt(pin, handler, edgeType) do {wiringPiISR(pin, edgeType, &handler);} while(0)

