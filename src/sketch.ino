#include "lcd_digit.h"

const unsigned int segment_a_pin = 11;
const unsigned int segment_b_pin = 12;
const unsigned int segment_c_pin =  5;
const unsigned int segment_d_pin =  7;
const unsigned int segment_e_pin =  6;
const unsigned int segment_f_pin =  9;
const unsigned int segment_g_pin =  8;

const unsigned int switch_pin = 3;

LcdDigit lcdDigit(segment_a_pin, segment_b_pin, segment_c_pin, segment_d_pin, segment_e_pin, segment_f_pin, segment_g_pin);

void rollRandomNumber(
  const unsigned int min, const unsigned int max,
  const unsigned int tries = 50, const unsigned int delay_time = 75
) {
  for(unsigned int i = 0; i < tries; i++) {
    const unsigned int number = random(min, max);
    lcdDigit.displayNumber(number);
    delay(delay_time);
  }
}

void setup()
{
  pinMode(switch_pin, INPUT);
  randomSeed(analogRead(A0));
}

unsigned int previousSwitchState = LOW;

void loop()
{
  const unsigned int switchState = digitalRead(switch_pin);
  if(switchState != previousSwitchState && switchState == HIGH) {
    rollRandomNumber(1, 6);
  }
  previousSwitchState = switchState;
}
