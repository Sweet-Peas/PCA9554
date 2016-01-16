/*
 * ----------------------------------------------------------------------------
 *            _____ _           _                   _
 *           | ____| | ___  ___| |_ _ __ ___  _ __ (_) ___
 *           |  _| | |/ _ \/ __| __| '__/ _ \| '_ \| |/ __|
 *           | |___| |  __/ (__| |_| | | (_) | | | | | (__
 *           |_____|_|\___|\___|\__|_|  \___/|_| |_|_|\___|
 *            ____                   _   ____
 *           / ___|_      _____  ___| |_|  _ \ ___  __ _ ___
 *           \___ \ \ /\ / / _ \/ _ \ __| |_) / _ \/ _` / __|
 *            ___) \ V  V /  __/  __/ |_|  __/  __/ (_| \__ \
 *           |____/ \_/\_/ \___|\___|\__|_|   \___|\__,_|___/
 *
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <pontus@sweetpeas.se> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return - Pontus Oldberg
 * ----------------------------------------------------------------------------
 */

#include <Wire.h>
#include <Pca9554.h>

#define SDA_PIN      2
#define SCL_PIN      14

void setup() {
  // Initialize the Pca9554 library
  Pca9554.begin(SDA_PIN, SCL_PIN);

  // Debug anyone
  Serial.begin(115200);
  Serial.println(F("\nPca9554 test initialized !"));

  // Initialization could also be done like this
  // Wire.begin(SDA_PIN, SCL_PIN);
  // Pca9554.begin();
  // Which is usefull if you have more than one +One
  // module in the system and the I2C bus only needs to be
  // initialized once.

  // Set pin mode of pins output
  Pca9554.pinMode(0, OUTPUT);
  Pca9554.pinMode(1, OUTPUT);
  Pca9554.pinMode(2, OUTPUT);
  Pca9554.pinMode(3, OUTPUT);
  Pca9554.pinMode(4, OUTPUT);
  Pca9554.pinMode(5, OUTPUT);
  Pca9554.pinMode(6, OUTPUT);
  Pca9554.pinMode(7, OUTPUT);

  // Make them low
  Pca9554.digitalWrite(0, LOW);
  Pca9554.digitalWrite(1, LOW);
  Pca9554.digitalWrite(2, LOW);
  Pca9554.digitalWrite(3, LOW);
  Pca9554.digitalWrite(4, LOW);
  Pca9554.digitalWrite(5, LOW);
  Pca9554.digitalWrite(6, LOW);
  Pca9554.digitalWrite(7, LOW);
}

void loop() {
  static uint8_t pin = 0;

  Serial.print(F("Blink pin "));
  Serial.println(pin, DEC);

  // toggle the current pin
  Pca9554.digitalWrite(pin, HIGH);
  delay(500);
  Pca9554.digitalWrite(pin, LOW);
  delay(500);

  // Get next pin in sequence
  if (++pin == 8)
    pin = 0;
}
