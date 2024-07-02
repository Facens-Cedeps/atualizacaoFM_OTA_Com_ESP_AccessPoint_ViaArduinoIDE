// ========================================================================================================

// ========================================================================================================
//---VOID SETUP OTA---
void SETUP_OTA() {
  /* Permite definir porta para conexão
      Padrão: ESP8266 - 8266
              ESP32   - 3232
  */
  //ArduinoOTA.setPort(port);

  /* Permite definir nome do host
      Padrão: ESP8266 - esp8266-[ChipID]
              ESP32   - esp32-[MAC]
  */
  ArduinoOTA.setHostname("Progeral - FW XXXX");

  /* Permite definir senha para acesso
      Padrão: sem senha
  */
  ArduinoOTA.setPassword("12345678");

  /* Permite definir senha para acesso via Hash MD5
      Padrão: sem senha
  */
  // ArduinoOTA.setPasswordHash("senhaHashMD5");

  //---define funções de callback do processo---

  //---início---
  ArduinoOTA.onStart([]() {
    String typeFile;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      typeFile = "sketch";
    } else { // U_SPIFFS
      typeFile = "filesystem";
    }
    Serial.println("Iniciando OTA - " + typeFile);
  });

  //---fim---
  ArduinoOTA.onEnd([]() {
    Serial.println("\nOTA Concluído.");
  });

  //---progresso---
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.print(progress * 100 / total);
    Serial.print(" ");
  });

  //---falha---
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.print("Erro " + String(error) + " ");
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Falha de autorização.");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Falha de inicialização.");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Falha de conexão.");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Falha de recebimento.");
    } else if (error == OTA_END_ERROR) {
      Serial.println("Falha de finalização");
    } else {
      Serial.println("Falha desconhecida.");
    }
  });

  //---inicializa OTA---
  ArduinoOTA.begin();

  //---pronto---
  Serial.println("Atualização via OTA disponível.");
//  Serial.print("Endereço IP: ");
//  Serial.println(WiFi.localIP());
}
// ========================================================================================================
