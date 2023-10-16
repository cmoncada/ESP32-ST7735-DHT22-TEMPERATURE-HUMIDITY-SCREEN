#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

// Define DHT PIN and SENSOR MODEL
#define DHTPIN 15
#define DHTTYPE DHT22

// Define TFT PIN setup
#define TFT_DC 7
#define TFT_CS 10
#define TFT_SDA 11
#define TFT_SCL 12
#define TFT_RST 6
#define SPI_FREQUENCY 40000000

// Initialize SENSOR AND TFT SCREEN
DHT dht(DHTPIN, DHTTYPE);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_SDA, TFT_SCL, TFT_RST);

void setup() {
  dht.begin();
  tft.setSPISpeed(SPI_FREQUENCY);
  tft.initR(INITR_MINI160x80_PLUGIN);
  tft.fillScreen(ST7735_BLACK);
  tft.setRotation(1);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  delay(10);

  tft.setCursor(10, 10);
  tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
  tft.setTextSize(2);
  tft.println("Temp: " + String(temperature));

  tft.setCursor(10, 30);
  tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
  tft.setTextSize(2);
  tft.println("Hum: " + String(humidity));
}