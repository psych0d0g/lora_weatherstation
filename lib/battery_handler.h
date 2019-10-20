#ifndef batt_handler_h
#define batt_handler_h

long lastReadBatt;

void checkBatt(unsigned long INTERVAL) {
  if (millis() - lastReadBatt >= INTERVAL){
    lastReadBatt = millis(); 
    float measuredvbat = analogRead(VBATPIN);
    measuredvbat *= 4.2;  // Multiply by 4.2V, our max batt voltage
    measuredvbat /= 1024; // convert to voltage
    lpp.addAnalogInput(1, measuredvbat);
  }
}

void charger(bool on) {
  DDRB |= (1<<PB0); // set PBO as output

  if(on) {
    PORTB |= (1<<PB0); 
    #ifdef SHOW_DEBUG
    	Serial.println("CHARGER ON");
    #endif
  } else {
    PORTB &= ~(1<<PB0); 
    #ifdef SHOW_DEBUG
    	Serial.println("CHARGER OFF");
    #endif
  } 
}

#endif