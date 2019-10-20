#ifndef wind_handler_h
#define wind_handler_h

#define WINDSPD_INTERVAL 60
#define ANEMOMETER_UMFANG 534

long lastWindSpdCalc;
int windSpeedCounter = 0;   // counter for the number of button presses
int windSpeedState = 0;         // current state of the button
int lastWindSpeedState = 0;     // previous state of the button

void handleWindspeed() {
    windSpeedState = expander.digitalRead(WINDSPD_PIN);
    if (windSpeedState != lastWindSpeedState) {
    	if (windSpeedState == LOW) {
    		windSpeedCounter++;
    		Serial.print("number of rotations: ");
            Serial.println(windSpeedCounter);
        }
    	delay(0);
    	lastWindSpeedState = windSpeedState;
	}
}

void collectAndSendWindspeed() {
	#ifdef SHOW_DEBUG
    	Serial.print("Avg Wind Speed last ");
     	Serial.print(LORAWAN_TX_INTERVAL_MAX);
    	Serial.print("s in km/h:");
    #endif
    int actualSpeed = ANEMOMETER_UMFANG*windSpeedCounter/2/1666;
    #ifdef SHOW_DEBUG
    	Serial.println(actualSpeed);
    #endif
    windSpeedCounter = 0;
	lpp.addAnalogInput(5, actualSpeed);
}

#endif