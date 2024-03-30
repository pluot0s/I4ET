
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#define buzzer D1

const char DEVICE_LOGIN_NAME[]  = "5c715364-bca5-4398-b8e8-587a3295e20d";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

bool activador;

void onActivadorChange(){
   if (activador) {
    digitalWrite(buzzer, HIGH); // Turn buzzer on
  } else {
    digitalWrite(buzzer, LOW); // Turn buzzer off
  }
}
 
void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(activador, READWRITE, ON_CHANGE, onActivadorChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
