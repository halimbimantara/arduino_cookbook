/*
 * https://wiki.dfrobot.com/DF-BluetoothV3_Bluetooth_module__SKU_TEL0026_
*/

#include <SoftwareSerial.h>

SoftwareSerial BTserial(6, 7); // RX | TX

#define __BAUD 38400

void setup(){
  Serial.begin(__BAUD);
  BTserial.begin(__BAUD);
  delay(1000);
  Serial.println("ready...");
}

void loop() {  
  if (BTserial.available()) {
    Serial.write(BTserial.read());
  }
  if (Serial.available()) {
    BTserial.write(Serial.read());
  }
}
