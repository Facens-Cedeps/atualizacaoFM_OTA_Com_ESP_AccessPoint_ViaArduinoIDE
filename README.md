# Atualização remota de firmware nas placas ESP 

## Justificativa
Atualização do firmware de forma remota e sem fio com o Over-the-air (OTA), nos projetos que utilizam as placas ESP. 

## O que é OTA
OTA é o acrônimo de Over-the-air que se refere a uma forma de atualização de software sem fio e de forma remota. OTA é um excelente recurso para aplicações IoT, pois os dispositivos podem ter firmwares e/ou configurações alterados sem a necessidade de serem recolhidos nem desmontados para serem reprogramados. 

Os ESP8266 e ESP32 tem suporte para esse recurso. Já existe uma biblioteca com exemplos para o framework Arduino.

### Formas de uso do OTA
- OTA via Arduino IDE: É a forma mais simples porque o upload é feito diretamente da Arduino IDE.
- OTA via upload de Imagem: O ESP mantém um pequeno servidor web e o usuário faz o upload dentro da interface desse servidor diretamente pelo navegador web.
- OTA via Servidor HTTP: Neste método existe um servidor HTTP que Hospeda o firmware e sempre que a alteração deste o ESP faz o download do firmware.

## Primeiro upload
Seja qualquer a forma de atualização OTA, o primeiro upload de firmware deve ser feito através de uma porta serial (USB).


## Bibliotecas

```c
	#include <WiFi.h>
	#include <ArduinoOTA.h>
```
## Configuração de conexão com rede por wifi

Neste exemplo, estamos usando o próprio processador como um Access Point. 

Essa opção foi escolhida para evitar a depedências de recursos terceiros para atualização. Por exemplo, nem sempre no local que será realizado o trabalhado há disponibilidade de sinal de internet (Wi-fi).
Durante o Setup, ele se conectará com as credenciais de rede que informamos. 

```c
	const char* ssid = ".........."; 
	const char* password = "..........";
```

## Atualização via OTA 
Neste exemplo, foi escolhido a opção via Arduino IDE. Já está considerado que você já fez o primeiro upload do código com as configurações e disponibilizado os recursos do OTA. 

No computador, conecte-se a rede criada no ESP.  Quando dois dispositivos estão ligados à mesma rede WiFi, podem comunicar entre si. Assim, é possível carregar o código através da rede WiFi sem ter de se ligar fisicamente a cada microcontrolador.

** Para manter a funcionalidade OTA, as futuras versões devem obrigatoriamente trazer as mesmas funções e chamadas OTA contidas no primeiro código.**

## Setup
```c
  Serial.begin(115200);

// Desativa o Wi-Fi para garantir que o AP seja configurado corretamente
  WiFi.disconnect(true);
  delay(1000);

  // Configura o ESP32 como Access Point
  WiFi.mode(WIFI_AP);
  //Remova o parâmetro da senha, se você que o AP(Access Point), para ficar com sinal aberto
  WiFi.softAP(ssid, password);

  // Espera a configuração do Access Point
  delay(2000);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: "); Serial.println(IP);
  
```

## Função loop
Recurso disponibilizado no loop principal para receber uma solicitação de uma atualização (OTA)
```c
void loop() {
  ArduinoOTA.handle();
}
```
## Métodos do processo OTA

- ** Permite definir nome do host **
  ArduinoOTA.setHostname("Cedeps - XXXXX");

- **Permite definir senha para acesso**  
  ArduinoOTA.setPassword("12345678");

```c
ArduinoOTA.onStart([]() {
	//...
});
```

```c
ArduinoOTA.onEnd([]() {
	//...
});
```
```c
ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
	//...
});
```

```c
ArduinoOTA.onError([](ota_error_t error) {
	//...
});
```

```c
 ArduinoOTA.begin();
```
## Orientação
Na pasta tutorial, existe um vídeo de demonstração e imagens guiando os passos

## Referências:
- <https://www.aranacorp.com/pt/programar-um-esp32-via-wifi-com-o-ide-arduino-ota/>
- <https://blog.smartkits.com.br/esp8266-32-programacao-sem-fio-ota/>
- <https://www.arduinoecia.com.br/programar-esp32-wifi-com-ota-over-the-air/>
- <https://www.makerhero.com/blog/atualizacao-de-software-ota-over-the-air-no-esp32/>
- <https://www.fernandok.com/2020/05/gravando-o-esp32-pela-internet-ota.html>
- <https://lastminuteengineers.com/esp32-ota-updates-arduino-ide/>
- <https://randomnerdtutorials.com/esp32-ota-over-the-air-arduino/>

