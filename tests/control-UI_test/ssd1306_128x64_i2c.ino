#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  Wire.begin(6, 7);
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 10);
  display.println(F("Hello ESP32"));
  display.display();
  delay(2000);
}

void loop() {
  Serial.println("yo");

  if (!digitalRead(2)) {
    delay(200);
    display.clearDisplay();
    display.drawRect(10, 20, 50, 20, SSD1306_WHITE);
    display.display();
  }

  if (!digitalRead(3)) {
    delay(200);
    display.clearDisplay();
    display.drawCircle(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 16, SSD1306_WHITE);
    display.display();
  }

}

