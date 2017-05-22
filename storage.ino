#include "functions.h"
#include "definitions.h"

//checks if the machine starts up for the first time and loads the factory presets if needed
uint8_t firstStartupCheck() {
  //we check if this is the first startup of the machine
  uint8_t byte1, byte2, byte3;

  byte1 = EEPROM.read(EEPROM.length() - 3);
  byte2 = EEPROM.read(EEPROM.length() - 2);
  byte3 = EEPROM.read(EEPROM.length() - 1);

  //if this is the first time this device is powered on
  if ((byte1 != 0xB0) && (byte2 != 0x0B) && (byte3 != 0x1E)) {  //"boobie" signature yay !
    return 1;
  }
  else return 0;
}

void formatFactory() {
  
  //First program the Last Used Preset : the first one
  EEPROM.update(0, 0x01);
  
  // Create default preset
  Preset_t defaultPreset;
  defaultPreset.channel = 1;

    defaultPreset.knobInfo[0].CC = 84;
    defaultPreset.knobInfo[0].NRPN = 0;
    defaultPreset.knobInfo[0].SYSEX = 128;
    defaultPreset.knobInfo[1].CC = 83;
    defaultPreset.knobInfo[1].NRPN = 0;
    defaultPreset.knobInfo[1].SYSEX = 128;
    defaultPreset.knobInfo[2].CC = 51;
    defaultPreset.knobInfo[2].NRPN = 0;
    defaultPreset.knobInfo[2].SYSEX = 128;
    defaultPreset.knobInfo[3].CC = 75;
    defaultPreset.knobInfo[3].NRPN = 0;
    defaultPreset.knobInfo[3].SYSEX = 128;
    defaultPreset.knobInfo[4].CC = 71;
    defaultPreset.knobInfo[4].NRPN = 0;
    defaultPreset.knobInfo[4].SYSEX = 128;
    defaultPreset.knobInfo[5].CC = 103;
    defaultPreset.knobInfo[5].NRPN = 0;
    defaultPreset.knobInfo[5].SYSEX = 128;
    defaultPreset.knobInfo[6].CC = 109;
    defaultPreset.knobInfo[6].NRPN = 0;
    defaultPreset.knobInfo[6].SYSEX = 128;
    defaultPreset.knobInfo[7].CC = 89;
    defaultPreset.knobInfo[7].NRPN = 0;
    defaultPreset.knobInfo[7].SYSEX = 128;
    defaultPreset.knobInfo[8].CC = 51 | 0x80;
    defaultPreset.knobInfo[8].NRPN = 0 | 0x80;
    defaultPreset.knobInfo[8].SYSEX = 128 + 11;
    defaultPreset.knobInfo[9].CC = 122;
    defaultPreset.knobInfo[9].NRPN = 0;
    defaultPreset.knobInfo[9].SYSEX = 128;
    defaultPreset.knobInfo[10].CC = 86;
    defaultPreset.knobInfo[10].NRPN = 0;
    defaultPreset.knobInfo[10].SYSEX = 128;
    defaultPreset.knobInfo[11].CC = 85;
    defaultPreset.knobInfo[11].NRPN = 0;
    defaultPreset.knobInfo[11].SYSEX = 128;
    defaultPreset.knobInfo[12].CC = 53;
    defaultPreset.knobInfo[12].NRPN = 0;
    defaultPreset.knobInfo[12].SYSEX = 128;
    defaultPreset.knobInfo[13].CC = 76;
    defaultPreset.knobInfo[13].NRPN = 0;
    defaultPreset.knobInfo[13].SYSEX = 128;
    defaultPreset.knobInfo[14].CC = 39;
    defaultPreset.knobInfo[14].NRPN = 0;
    defaultPreset.knobInfo[14].SYSEX = 128;
    defaultPreset.knobInfo[15].CC = 45;
    defaultPreset.knobInfo[15].NRPN = 0;
    defaultPreset.knobInfo[15].SYSEX = 128;
    defaultPreset.knobInfo[16].CC = 110;
    defaultPreset.knobInfo[16].NRPN = 0;
    defaultPreset.knobInfo[16].SYSEX = 128;
    defaultPreset.knobInfo[17].CC = 90;
    defaultPreset.knobInfo[17].NRPN = 0;
    defaultPreset.knobInfo[17].SYSEX = 128;
    defaultPreset.knobInfo[18].CC = 52 | 0x80;
    defaultPreset.knobInfo[18].NRPN = 0 | 0x80;
    defaultPreset.knobInfo[18].SYSEX = 128 + 11;
    defaultPreset.knobInfo[19].CC = 123;
    defaultPreset.knobInfo[19].NRPN = 0;
    defaultPreset.knobInfo[19].SYSEX = 128;
    defaultPreset.knobInfo[20].CC = 13;
    defaultPreset.knobInfo[20].NRPN = 0;
    defaultPreset.knobInfo[20].SYSEX = 128;
    defaultPreset.knobInfo[21].CC = 87;
    defaultPreset.knobInfo[21].NRPN = 0;
    defaultPreset.knobInfo[21].SYSEX = 128;
    defaultPreset.knobInfo[22].CC = 55;
    defaultPreset.knobInfo[22].NRPN = 0;
    defaultPreset.knobInfo[22].SYSEX = 128;
    defaultPreset.knobInfo[23].CC = 77;
    defaultPreset.knobInfo[23].NRPN = 0;
    defaultPreset.knobInfo[23].SYSEX = 128;
    defaultPreset.knobInfo[24].CC = 40;
    defaultPreset.knobInfo[24].NRPN = 0;
    defaultPreset.knobInfo[24].SYSEX = 128;
    defaultPreset.knobInfo[25].CC = 46;
    defaultPreset.knobInfo[25].NRPN = 0;
    defaultPreset.knobInfo[25].SYSEX = 128;
    defaultPreset.knobInfo[26].CC = 111;
    defaultPreset.knobInfo[26].NRPN = 0;
    defaultPreset.knobInfo[26].SYSEX = 128;
    defaultPreset.knobInfo[27].CC = 91;
    defaultPreset.knobInfo[27].NRPN = 0;
    defaultPreset.knobInfo[27].SYSEX = 128;
    defaultPreset.knobInfo[28].CC = 53 | 0x80;
    defaultPreset.knobInfo[28].NRPN = 0 | 0x80;
    defaultPreset.knobInfo[28].SYSEX = 128 + 11;
    defaultPreset.knobInfo[29].CC = 124;
    defaultPreset.knobInfo[29].NRPN = 0;
    defaultPreset.knobInfo[29].SYSEX = 128;
    defaultPreset.knobInfo[30].CC = 15;
    defaultPreset.knobInfo[30].NRPN = 0;
    defaultPreset.knobInfo[30].SYSEX = 128;
    defaultPreset.knobInfo[31].CC = 29;
    defaultPreset.knobInfo[31].NRPN = 0;
    defaultPreset.knobInfo[31].SYSEX = 128;
    defaultPreset.knobInfo[32].CC = 57;
    defaultPreset.knobInfo[32].NRPN = 0;
    defaultPreset.knobInfo[32].SYSEX = 128;
    defaultPreset.knobInfo[33].CC = 78;
    defaultPreset.knobInfo[33].NRPN = 0;
    defaultPreset.knobInfo[33].SYSEX = 128;
    defaultPreset.knobInfo[34].CC = 41;
    defaultPreset.knobInfo[34].NRPN = 0;
    defaultPreset.knobInfo[34].SYSEX = 128;
    defaultPreset.knobInfo[35].CC = 47;
    defaultPreset.knobInfo[35].NRPN = 0;
    defaultPreset.knobInfo[35].SYSEX = 128;
    defaultPreset.knobInfo[36].CC = 112;
    defaultPreset.knobInfo[36].NRPN = 0;
    defaultPreset.knobInfo[36].SYSEX = 128;
    defaultPreset.knobInfo[37].CC = 92;
    defaultPreset.knobInfo[37].NRPN = 0;
    defaultPreset.knobInfo[37].SYSEX = 128;
    defaultPreset.knobInfo[38].CC = 54 | 0x80;
    defaultPreset.knobInfo[38].NRPN = 0 | 0x80;
    defaultPreset.knobInfo[38].SYSEX = 128 + 11;
    defaultPreset.knobInfo[39].CC = 125;
    defaultPreset.knobInfo[39].NRPN = 0;
    defaultPreset.knobInfo[39].SYSEX = 128;
    defaultPreset.knobInfo[40].CC = 17;
    defaultPreset.knobInfo[40].NRPN = 0;
    defaultPreset.knobInfo[40].SYSEX = 128;
    defaultPreset.knobInfo[41].CC = 58;
    defaultPreset.knobInfo[41].NRPN = 0;
    defaultPreset.knobInfo[41].SYSEX = 128;
    defaultPreset.knobInfo[42].CC = 59;
    defaultPreset.knobInfo[42].NRPN = 0;
    defaultPreset.knobInfo[42].SYSEX = 128;
    defaultPreset.knobInfo[43].CC = 67;
    defaultPreset.knobInfo[43].NRPN = 0;
    defaultPreset.knobInfo[43].SYSEX = 128;
    defaultPreset.knobInfo[44].CC = 42;
    defaultPreset.knobInfo[44].NRPN = 0;
    defaultPreset.knobInfo[44].SYSEX = 128;
    defaultPreset.knobInfo[45].CC = 48;
    defaultPreset.knobInfo[45].NRPN = 0;
    defaultPreset.knobInfo[45].SYSEX = 128;
    defaultPreset.knobInfo[46].CC = 113;
    defaultPreset.knobInfo[46].NRPN = 0;
    defaultPreset.knobInfo[46].SYSEX = 128;
    defaultPreset.knobInfo[47].CC = 93;
    defaultPreset.knobInfo[47].NRPN = 0;
    defaultPreset.knobInfo[47].SYSEX = 128;
    defaultPreset.knobInfo[48].CC = 55 | 0x80;
    defaultPreset.knobInfo[48].NRPN = 0 | 0x80;
    defaultPreset.knobInfo[48].SYSEX = 128 + 11;
    defaultPreset.knobInfo[49].CC = 126;
    defaultPreset.knobInfo[49].NRPN = 0;
    defaultPreset.knobInfo[49].SYSEX = 128;
    defaultPreset.knobInfo[50].CC = 19;
    defaultPreset.knobInfo[50].NRPN = 0;
    defaultPreset.knobInfo[50].SYSEX = 128;
    defaultPreset.knobInfo[51].CC = 61;
    defaultPreset.knobInfo[51].NRPN = 0;
    defaultPreset.knobInfo[51].SYSEX = 128;
    defaultPreset.knobInfo[52].CC = 62;
    defaultPreset.knobInfo[52].NRPN = 0;
    defaultPreset.knobInfo[52].SYSEX = 128;
    defaultPreset.knobInfo[53].CC = 68;
    defaultPreset.knobInfo[53].NRPN = 0;
    defaultPreset.knobInfo[53].SYSEX = 128;
    defaultPreset.knobInfo[54].CC = 43;
    defaultPreset.knobInfo[54].NRPN = 0;
    defaultPreset.knobInfo[54].SYSEX = 128;
    defaultPreset.knobInfo[55].CC = 49;
    defaultPreset.knobInfo[55].NRPN = 0;
    defaultPreset.knobInfo[55].SYSEX = 128;
    defaultPreset.knobInfo[56].CC = 114;
    defaultPreset.knobInfo[56].NRPN = 0;
    defaultPreset.knobInfo[56].SYSEX = 128;
    defaultPreset.knobInfo[57].CC = 94;
    defaultPreset.knobInfo[57].NRPN = 0;
    defaultPreset.knobInfo[57].SYSEX = 128;
    defaultPreset.knobInfo[58].CC = 56 | 0x80;
    defaultPreset.knobInfo[58].NRPN = 0 | 0x80;
    defaultPreset.knobInfo[58].SYSEX = 128 + 11;
    defaultPreset.knobInfo[59].CC = 127;
    defaultPreset.knobInfo[59].NRPN = 0;
    defaultPreset.knobInfo[59].SYSEX = 128;
  
  defaultPreset.invertBits = 0;
  defaultPreset.dropNRPNLSBvalue = 0;
  
  // we write the default preset to all preset slots, byte by byte
  uint16_t baseAddress = 1;
  for (uint8_t p=0; p<NUMBEROFPRESETS; p++) { 
    for (uint16_t byteIndex=0; byteIndex<sizeof(Preset_t); byteIndex++) {
      EEPROM.update(baseAddress + p*sizeof(Preset_t) + byteIndex, ((uint8_t*)(&defaultPreset))[byteIndex]);
    }
  }
  
  //we write the signature so that the device will never rewrite the factory presets
  EEPROM.update(EEPROM.length() - 3, 0xB0);
  EEPROM.update(EEPROM.length() - 2, 0x0B);
  EEPROM.update(EEPROM.length() - 1, 0x1E);
}


//Loads the specified preset in the RAM and make it the last used preset
void loadPreset(uint8_t presetNumber) {
  
  uint16_t baseAddress = presetNumber * sizeof(Preset_t) + 1;

  // read the active preset from EEPROM; byte by byte  
  for (uint16_t byteIndex=0; byteIndex<sizeof(Preset_t); byteIndex++) {
    ((uint8_t*)(&activePreset))[byteIndex] = EEPROM.read(baseAddress + byteIndex);
  }

  //update the last used preset
  EEPROM.update(0, presetNumber);
}



void savePreset(uint8_t presetNbr)
{
  uint16_t baseAddress = presetNbr * sizeof(Preset_t) + 1;

  // write the active preset to EEPROM; byte by byte  
  for (uint16_t byteIndex=0; byteIndex<sizeof(Preset_t); byteIndex++) {
    EEPROM.update(baseAddress + byteIndex, ((uint8_t*)(&activePreset))[byteIndex]);
  }
  
  //Visual feedback
  //we wait a bit with the LED oon
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  //we blink it
  digitalWrite(LED_PIN, LOW);
  delay(250);
  digitalWrite(LED_PIN, HIGH);
  delay(250);
  digitalWrite(LED_PIN, LOW);
}
