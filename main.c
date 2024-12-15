#include <dht.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <U8g2lib.h> 

#define PUMP_PIN 2
#define PUMP_UPTIME_SECONDS 10

#define SOIL_MOISTURE_PIN A0
const int SOIL_WET_THRESHOLD = 239;
const int SOIL_DRY_THRESHOLD = 595;

#define DHT_PIN 4
dht DHT;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OPTIMAL_SOIL_MOISTURE_LOW_THRESHOLD 20
#define OPTIMAL_SOIL_MOISTURE_UPPER_THRESHOLD 60

#define OPTIMAL_AIR_HUMIDITY_LOW_THRESHOLD 60
#define OPTIMAL_AIR_HUMIDITY_UPPER_THRESHOLD 80

#define OPTIMAL_AIR_TEMPERATURE_LOW_THRESHOLD 25
#define OPTIMAL_AIR_TEMPERATURE_UPPER_THRESHOLD 28

#define PIEZO_PIN 9
#define LED_PIN 7
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);

int userIsAlerted = 0;

void setup() {
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(PIEZO_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  u8g2.setFont(u8g2_font_6x10_tf);
}

void loop() {
  int readData = DHT.read22(DHT_PIN);
  float airHumidity = getAirHumidity();
  float airTemperature = getAirTemperature();
  int soilMoisture = getSoilMoisturePercentage();

  writeDataToScreen(airTemperature,airHumidity,soilMoisture);

  if(soilMoisture < OPTIMAL_SOIL_MOISTURE_LOW_THRESHOLD)
  {
    turnOnPump();
  }
  
  delay(5000);

}

void writeDataToScreen(float airTemperature, float airHumidity, int soilMoisture)
{
  u8g2.begin();

  u8g2.drawStr(3,15,"Air temp:");
  u8g2.setCursor(60, 15);
  u8g2.print(airTemperature);
  u8g2.drawStr(90,15,"C");

  u8g2.drawStr(3,35,"Humidity:");
  u8g2.setCursor(60, 35);
  u8g2.print(airHumidity);
  u8g2.drawStr(90,35,"%");

  u8g2.drawStr(3,55,"S. moisture:");
  u8g2.setCursor(80, 55);
  u8g2.print(soilMoisture);
  u8g2.drawStr(95,55,"%");

  u8g2.sendBuffer();
}

float getAirHumidity()
{
  return DHT.humidity;
}

float getAirTemperature()
{
  return DHT.temperature;
}

void turnOnPump()
{
  digitalWrite(PUMP_PIN, HIGH);
  delay(PUMP_UPTIME_SECONDS * 1000);
  digitalWrite(PUMP_PIN, LOW);
}

int getSoilMoisturePercentage()
{
  int sensorValue = analogRead(SOIL_MOISTURE_PIN);
  return map(sensorValue, SOIL_WET_THRESHOLD, SOIL_DRY_THRESHOLD, 100, 0);
}
