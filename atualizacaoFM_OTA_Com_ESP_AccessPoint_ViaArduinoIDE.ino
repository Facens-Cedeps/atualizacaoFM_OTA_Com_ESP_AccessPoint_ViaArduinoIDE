/*
  Atualização de software OTA (Over-The-Air)
*/
#include <WiFi.h>
#include <ArduinoOTA.h>

#define LED 2

const char* ssid = "ESP32-AP";
const char* password = "12345678";


void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

  // Desativa o Wi-Fi para garantir que o AP seja configurado corretamente
  WiFi.disconnect(true);
  delay(1000);

  // Configura o ESP32 como Access Point
  WiFi.mode(WIFI_AP);
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  // Espera a configuração do Access Point
  delay(2000);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  SETUP_OTA();
}

void loop() {
  //---chamar função OTA---
  ArduinoOTA.handle();
  Serial.println("RUNNING 5 - 02/07/2024");
  delay(1000);
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);

}
