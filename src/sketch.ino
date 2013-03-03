const unsigned int segment_a_pin = 11;
const unsigned int segment_b_pin = 12;
const unsigned int segment_c_pin =  5;
const unsigned int segment_d_pin =  7;
const unsigned int segment_e_pin =  6;
const unsigned int segment_f_pin =  9;
const unsigned int segment_g_pin =  8;

const unsigned int all_segments[] = {
  segment_a_pin,
  segment_b_pin,
  segment_c_pin,
  segment_d_pin,
  segment_e_pin,
  segment_g_pin,
  segment_f_pin,
  NULL
};

const unsigned int zero[]  = { segment_a_pin, segment_b_pin, segment_c_pin, segment_d_pin, segment_e_pin, segment_f_pin,                NULL };
const unsigned int one[]   = {                segment_b_pin, segment_c_pin,                                                             NULL };
const unsigned int two[]   = { segment_a_pin, segment_b_pin,                segment_d_pin, segment_e_pin,                segment_g_pin, NULL };
const unsigned int three[] = { segment_a_pin, segment_b_pin, segment_c_pin, segment_d_pin,                               segment_g_pin, NULL };
const unsigned int four[]  = {                segment_b_pin, segment_c_pin,                               segment_f_pin, segment_g_pin, NULL };
const unsigned int five[]  = { segment_a_pin,                segment_c_pin, segment_d_pin,                segment_f_pin, segment_g_pin, NULL };
const unsigned int six[]   = { segment_a_pin,                segment_c_pin, segment_d_pin, segment_e_pin, segment_f_pin, segment_g_pin, NULL };
const unsigned int seven[] = { segment_a_pin, segment_b_pin, segment_c_pin,                                                             NULL };
const unsigned int eight[] = { segment_a_pin, segment_b_pin, segment_c_pin, segment_d_pin, segment_e_pin, segment_f_pin, segment_g_pin, NULL };
const unsigned int nine[]  = { segment_a_pin, segment_b_pin, segment_c_pin, segment_d_pin,                segment_f_pin, segment_g_pin, NULL };

const unsigned int *numbers[] = {
  zero, one, two, three, four, five, six, seven, eight, nine
};

const unsigned int delay_time = 1000;

void digitalWriteSegments(const unsigned int segments[], const unsigned int level) {
  for(const unsigned int *segment = segments; *segment != NULL; segment++) {
    digitalWrite(*segment, level);
  }
}

void clearSegments(const unsigned int segments[]) {
  digitalWriteSegments(segments, HIGH);
}

void clearAllSegments() {
  clearSegments(all_segments);
}

void lightSegments(const unsigned int segments[]) {
  digitalWriteSegments(segments, LOW);
}

void displayNumber(const unsigned int number) {
  clearAllSegments();
  lightSegments(numbers[number]);
}

void setup()
{
  for(const unsigned int *segment = all_segments; *segment != NULL; segment++) {
    pinMode(*segment, OUTPUT);
  }
  clearAllSegments();
}

void loop()
{
  for(unsigned int i = 0; i < 10; i++) {
    displayNumber(i);
    delay(delay_time);
  }
}
