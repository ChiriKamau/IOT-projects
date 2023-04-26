#define BLYNK_TEMPLATE_ID "TMPL5TZMXU7Jy"
#define BLYNK_TEMPLATE_NAME "ChiriSmartHome"
#define BLYNK_AUTH_TOKEN "BsjiLCgMQfkqwSc3ifh5ArYUqy66Qyug"

#define BLYNK_PRINT Serial


#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ocean";
char pass[] = "iris2012";

//Software Serial on Uno
#include <SoftwareSerial.h>

//SoftwareSerial EspSerial(2, 3); // RX, TX
// Your ESP8266 baud rate:
#define ESP8266_BAUD 38400

ESP8266 wifi(&EspSerial);

void setup()
{
  // Debug console
  Serial.begin(115200);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass);
 

}

void loop()
{
  Blynk.run();
  
}
BLYNK_WRITE(V1)
{
  int button1Value = param.asInt(); // assigning incoming value from pin V1 to a variable
  
  digitalWrite(relay1, button1Value);
  
}
BLYNK_WRITE(V2)
{
  int button2Value = param.asInt(); // assigning incoming value from pin V2 to a variable

  digitalWrite(relay2, button2Value);
}
BLYNK_WRITE(V3)
{
  int button3Value = param.asInt(); // assigning incoming value from pin V3 to a variable

  digitalWrite(relay3, button3Value);
}
BLYNK_WRITE(A1)
{
  int button4Value = param.asInt(); // assigning incoming value from pin A1 to a variable

  analogWrite(relay4, fan);
}
