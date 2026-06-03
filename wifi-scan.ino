#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define SENSOR_A 12
#define SENSOR_B 5

const char* ssid = "Wokwi-GUEST";
const char* password = "";

// TOKEN DO DEVICE TAGOIO
String token = "ee78d47e-422b-45c4-8664-a9c3d6065b21";

LiquidCrystal_I2C lcd(0x27, 16, 2);

int contador = 0;
int totalEntradas = 0;
int totalSaidas = 0;

// FUNÇÃO PARA ENVIAR DADOS AO TAGOIO
void enviarTagoIO() {

  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    http.begin("https://api.tago.io/data");

    http.addHeader("Content-Type", "application/json");
    http.addHeader("Device-Token", token);

    String json = "[";

    json += "{\"variable\":\"pessoas_atuais\",\"value\":";
    json += contador;
    json += "},";

    json += "{\"variable\":\"total_Entradas\",\"value\":";
    json += totalEntradas;
    json += "},";

    json += "{\"variable\":\"total_Saidas\",\"value\":";
    json += totalSaidas;
    json += "}";

    json += "]";

    Serial.println("JSON enviado:");
    Serial.println(json);

    int httpResponseCode = http.POST(json);

    String response = http.getString();

    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);

    Serial.print("Resposta servidor: ");
    Serial.println(response);

    http.end();

  } else {

    Serial.println("WiFi desconectado");
  }
}

void atualizarLCD() {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Pessoas:");

  lcd.setCursor(10, 0);
  lcd.print(contador);

  lcd.setCursor(0, 1);
  lcd.print("E:");
  lcd.print(totalEntradas);

  lcd.print(" S:");
  lcd.print(totalSaidas);
}

void setup() {

  Serial.begin(115200);

  // WIFI
  WiFi.begin(ssid, password);

  Serial.print("Conectando WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Conectado");

  // SENSORES
  pinMode(SENSOR_A, INPUT);
  pinMode(SENSOR_B, INPUT);

  // LCD
  lcd.init();
  lcd.backlight();

  atualizarLCD();

  // ENVIA DADOS INICIAIS
  enviarTagoIO();
}

// HIGH = detectou pessoa
// LOW = não detectou

void loop() {

  int estadoA = digitalRead(SENSOR_A);
  int estadoB = digitalRead(SENSOR_B);

  // =========================
  // PESSOA ENTRANDO
  // =========================
  if (estadoA == HIGH) {

    delay(200);

    if (digitalRead(SENSOR_B) == HIGH) {

      contador++;
      totalEntradas++;

      Serial.print("Entrou... QTD Atual: ");
      Serial.println(contador);

      atualizarLCD();

      enviarTagoIO();

      // AGUARDA SENSORES LIBERAREM
      while (digitalRead(SENSOR_A) == HIGH ||
             digitalRead(SENSOR_B) == HIGH) {
        delay(1);
      }
    }
  }

  // =========================
  // PESSOA SAINDO
  // =========================
  if (estadoB == HIGH) {

    delay(200);

    if (digitalRead(SENSOR_A) == HIGH) {

      if (contador > 0) {
        contador--;
        totalSaidas++;
      }

      if (contador < 0) {
        contador = 0;
      }

      Serial.print("Saiu... QTD Atual: ");
      Serial.println(contador);

      atualizarLCD();

      enviarTagoIO();

      // AGUARDA SENSORES LIBERAREM
      while (digitalRead(SENSOR_A) == HIGH ||
             digitalRead(SENSOR_B) == HIGH) {
        delay(1);
      }
    }
  }
}