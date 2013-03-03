#include "lcd_digit.h"
#include "button.h"
#include "die.h"

const unsigned int segment_a_pin = 11;
const unsigned int segment_b_pin = 12;
const unsigned int segment_c_pin =  5;
const unsigned int segment_d_pin =  7;
const unsigned int segment_e_pin =  6;
const unsigned int segment_f_pin =  9;
const unsigned int segment_g_pin =  8;

const unsigned int buttonPin = 3;

LcdDigit lcdDigit(segment_a_pin, segment_b_pin, segment_c_pin, segment_d_pin, segment_e_pin, segment_f_pin, segment_g_pin);
Button   button(buttonPin);
Die      die(lcdDigit, button, 10);

void setup()
{
}

void loop()
{
  die.run();
}
