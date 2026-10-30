#include "DHT.h"

#define DHTPIN 4     // Pin GPIO4
#define DHTTYPE DHT11   // Definimos que es el DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println(F("Iniciando sensor DHT11..."));
  dht.begin();
}

void loop() {
  delay(2000); // Esperar 2 segundos entre mediciones

  // Leer humedad
  float h = dht.readHumidity();
  // Leer temperatura en Celsius
  float t = dht.readTemperature();

  // Comprobar si ha habido algún fallo en la lectura
  if (isnan(h) || isnan(t)) {
    Serial.println(F("¡Error! No se puede leer del sensor DHT11 (Revisa Vin y conexiones)."));
    return;
  }

  Serial.print(F("Humedad: "));
  Serial.print(h);
  Serial.print(F("%  |  Temperatura: "));
  Serial.print(t);
  Serial.println(F("°C"));
}