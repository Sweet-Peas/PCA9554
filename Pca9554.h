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
#ifndef __GUARD_PCA9554_H__
#define __GUARD_PCA9554_H__

#include <Arduino.h>
#include <Wire.h>

#define NORMAL                          0
#define INVERTED                        1

class Pca9554Class
{
protected:
 public:
  Pca9554Class();
  void    begin(void);
#if defined(ARDUINO_ARCH_ESP8266)
  void    begin(uint8_t sda, uint8_t scl);
#endif
  boolean pinMode(uint8_t pin, uint8_t mode);
  boolean pinPolarity(uint8_t pin, uint8_t polarity);
  boolean digitalWrite(uint8_t pin, boolean val);
  boolean digitalRead(uint8_t pin);

 private:
  uint8_t m_inp;
  uint8_t m_out;
  uint8_t m_pol;
  uint8_t m_ctrl;
};

extern Pca9554Class Pca9554;

#endif //ifndef __GUARD_PCA9554_H__

// EOF
