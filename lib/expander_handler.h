#ifndef expander_handler_h
#define expander_handler_h

PCF8575 expander;

void setupExpander(){
  expander.begin(0x20);
  expander.pinMode(WINDSPD_PIN, INPUT);
  expander.pinMode(WINDDIR_N_PIN, INPUT_PULLUP);
  expander.pinMode(WINDDIR_NE_PIN, INPUT_PULLUP);
  expander.pinMode(WINDDIR_E_PIN, INPUT_PULLUP);
  expander.pinMode(WINDDIR_SE_PIN, INPUT_PULLUP);
  expander.pinMode(WINDDIR_S_PIN, INPUT_PULLUP);
  expander.pinMode(WINDDIR_SW_PIN, INPUT_PULLUP);
  expander.pinMode(WINDDIR_W_PIN, INPUT_PULLUP);
  expander.pinMode(WINDDIR_NW_PIN, INPUT_PULLUP);
}

#endif