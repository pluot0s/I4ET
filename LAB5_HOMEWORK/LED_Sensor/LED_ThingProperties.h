#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#define RED_PIN D1
#define GREEN_PIN D2
#define BLUE_PIN D3

const char DEVICE_LOGIN_NAME[]  = "5c715364-bca5-4398-b8e8-587a3295e20d";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password



bool azul;
bool rojo;
bool verde;

void onRojoChange() {
  digitalWrite(RED_PIN, rojo ? HIGH : LOW);
}

void onVerdeChange() {
  digitalWrite(GREEN_PIN, verde ? HIGH : LOW);
}

void onAzulChange() {
  digitalWrite(BLUE_PIN, azul ? HIGH : LOW);
}

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(azul, READWRITE, ON_CHANGE, onAzulChange);
  ArduinoCloud.addProperty(rojo, READWRITE, ON_CHANGE, onRojoChange);
  ArduinoCloud.addProperty(verde, READWRITE, ON_CHANGE, onVerdeChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
