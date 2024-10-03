#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>
#include <Wire.h>

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

String emotion = "";  // to store the incoming emotion

void setup() {
  Serial.begin(9600);
  matrix.begin(0x70);  // Initialize the 8x8 matrix at I2C address 0x70
}

void loop() {
  if (Serial.available() > 0) {
    emotion = Serial.readString();  // Read the emotion from serial
    
    matrix.clear();  // Clear the display
    if (emotion == "hap") {
      displayHappyFace();
    } else if (emotion == "sad") {
      displaySadFace();
    } else if (emotion == "ang") {
      displayAngryFace();
    } else if (emotion == "neu") {
      displayNeutralFace();
    } else if (emotion == "fea") {
      displayFearFace();
    }
    matrix.writeDisplay();  // Update the display
  }
}

void displayHappyFace() {
  // Create a simple happy face on the 8x8 LED matrix
  uint8_t happyFace[8] = {0x3C, 0x42, 0xA5, 0x81, 0x81, 0xA5, 0x99, 0x42};
  matrix.drawBitmap(0, 0, happyFace, 8, 8, LED_ON);
}

void displaySadFace() {
  // Create a sad face pattern
  uint8_t sadFace[8] = {0x3C, 0x42, 0xA5, 0x81, 0x81, 0xC3, 0x66, 0x42};
  matrix.drawBitmap(0, 0, sadFace, 8, 8, LED_ON);
}

void displayAngryFace() {
  // Create an angry face pattern
  uint8_t angryFace[8] = {0x3C, 0x42, 0xE7, 0x81, 0x81, 0x99, 0xA5, 0x42};
  matrix.drawBitmap(0, 0, angryFace, 8, 8, LED_ON);
}

void displayNeutralFace() {
  // Create a neutral face pattern
  uint8_t neutralFace[8] = {0x3C, 0x42, 0xA5, 0x81, 0x81, 0x81, 0x42, 0x42};
  matrix.drawBitmap(0, 0, neutralFace, 8, 8, LED_ON);
}

void displayFearFace() {
  // Create a fear face pattern
  uint8_t fearFace[8] = {0x3C, 0x42, 0xE7, 0x81, 0x81, 0xC3, 0x42, 0x42};
  matrix.drawBitmap(0, 0, fearFace, 8, 8, LED_ON);
}
