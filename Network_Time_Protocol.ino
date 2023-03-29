//Bibliotecas
#include "WiFi.h"
#include "ESP32Time.h"

//Datos de la red
const char* ssid = "*****";
const char* password = "*****";

//Configuracion del servidor NTP
const char* ntpServer = "pool.ntp.org"; //Servidor NTP
const long gmtOffset_sec = -5*3600;     //Desplazamiento GMT
const int daylightOffset_sec = 0;       //Compensacion de luz diurna

ESP32Time rtc;

void setup() {
  // Monitor Serie
  Serial.begin(115200);

  // Conexion a la red
  Serial.print("Conectando a la red ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado");

  // Configuracion de la hora
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop() {
  Serial.println(rtc.getTime("%A, %B %d %Y %H:%M:%S")); //Funcion para imprimir la fehca y hora
 
  delay(1000);
}