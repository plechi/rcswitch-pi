// replace detachInterrupt() with a empty block
#define detachInterrupt(x) do { } while(0)

// map attachInterrupt() to wiringPi equivalent
#define attachInterrupt(pin, handler, edgeType)		\
		do {	 									\
			wiringPiISR(pin, edgeType, &handler);	\
		} while(0)