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

  // Initialization could also be done like this
  // Wire.begin(SDA_PIN, SCL_PIN);
  // Pca9554.begin();
  // Which is usefull if you have more than one +One
  // module in the system and the I2C bus only needs to be
  // initialized once.

  // Set pin mode of pin 0 to output
  Pca9554.pinMode(0, OUTPUT);

  // Make it low
  Pca9554.digitalWrite(0, HIGH);
}

void loop() {
  // Make pin 0 high for a while
  Pca9554.digitalWrite(0, HIGH);
  delay(500);

  // And bring it low again
  Pca9554.digitalWrite(0, LOW);
  delay(500);
}

