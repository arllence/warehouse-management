#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <SPI.h>
#include <MFRC522.h>

constexpr uint8_t RST_PIN = D3;     // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = D4;     // Configurable, see typical pin layout above
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key;
String tag;

const char* ssid = "amos-phone";
const char* password = "@Ariah04";

const char* serverName = "http://b6cac288f595.ngrok.io/RFID/cart?format=json"; //api

String payload;


HTTPClient http;

 
void setup() {
  Serial.begin(9600);
  
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP()); 

}

void loop() {

    if(WiFi.status()== WL_CONNECTED){
     if ( ! rfid.PICC_IsNewCardPresent()){ return;}
     if (rfid.PICC_ReadCardSerial()) {
     for (byte i = 0; i < 4; i++) {
        tag += rfid.uid.uidByte[i];
       }
      Serial.println(tag);
      http.begin(serverName);
      http.addHeader("Content-Type","application/json");
      String payload = "{\"object_id\":\""+tag+"\"}";
      Serial.println(payload);
      int response_status = http.POST(payload);
      Serial.println(response_status);
      tag = "";
      rfid.PICC_HaltA();
      rfid.PCD_StopCrypto1();
      }

    }
    else {
      Serial.println("WiFi Disconnected");
    }
}
