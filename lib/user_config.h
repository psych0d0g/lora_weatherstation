#ifndef user_config_h
#define user_config_h

//Uncomment to enable lora debug messages on console
//#define SHOW_DEBUG true

// Pin definitions to match your board
#define LEDPIN 13
#define VBATPIN 9

#define WINDSPD_PIN 0

#define WINDDIR_N_PIN 1
#define WINDDIR_NE_PIN 2
#define WINDDIR_E_PIN 3
#define WINDDIR_SE_PIN 4
#define WINDDIR_S_PIN 5
#define WINDDIR_SW_PIN 6
#define WINDDIR_W_PIN 7
#define WINDDIR_NW_PIN 8

//How often to send lora updates
#define LORAWAN_TX_INTERVAL_MAX 60  // seconds between LoraWan messages

//Enable charger circuit or not
bool charger_state = true;

#endif