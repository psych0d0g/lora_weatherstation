#include <Wire.h>
#include <CayenneLPP.h>
#include "keys.h"
#include <BlueDot_BME680.h>
#include <PCF8575.h>
#include "lib/user_config.h"
#include "lib/lorawan.h"
#include "lib/battery_handler.h"
#include "lib/bme680_handler.h"
#include "lib/expander_handler.h"
#include "lib/wind_handler.h"

long lastLoraSend;

void setup()
  {
  pinMode(LEDPIN, OUTPUT);
  delay(1500);
  Serial.begin(115200);
  Serial.println("\nStarting device."); 
  Wire.begin();   
  setupExpander();
  setupBme680();  
  charger(charger_state);
  LoraWan_init();  // --> init and also send one message    
  lmic_slim_init();
  Serial.print("Setup() completed.");
}


void loop()
{
  if (millis() - lastLoraSend >= LORAWAN_TX_INTERVAL_MAX * 1000L){
    lastLoraSend = millis(); 
    lpp.reset();
    checkBatt(0);
    handleBme680();
    collectAndSendWindspeed();
    LoraWan_send();
  }
  handleWindspeed();
}
