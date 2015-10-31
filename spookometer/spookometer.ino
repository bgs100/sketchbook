// Configuration: 2 7-segment displays (common anode) wired up to 2 74259 ICs.
// http://www.unicornelectronics.com/ftp/Data%20Sheets/74259.pdf
// The mapping of pins on the first IC to the Arduino is 1 -> 13, 2 -> 12, 3 -> 11, 14 -> 10, and 13 -> 9.
// Same for the second IC, but with the Arduino pins 3-7 instead of 9-13. Pin 8 is a digital input.
// Pin 15 of each IC is wired high.

// Layout of Addresses:
//  7
// 0 6
//  1
// 2 5
//  3 4 (.)

int order[8] = { 7, 0, 6, 1, 2, 5, 3, 4 };

// Representations of the digits 0-9 for the 7-segment displays.
// Indices correspond to segments like so:
//  0
// 1 2
//  3
// 4 5
//  6 7 (.)
// 1 = lit, 0 = unlit.
boolean numbers[10][8] = { { 1, 1, 1, 0, 1, 1, 1, 0 },
                           { 0, 0, 1, 0, 0, 1, 0, 0 },
                           { 1, 0, 1, 1, 1, 0, 1, 0 },
                           { 1, 0, 1, 1, 0, 1, 1, 0 },
                           { 0, 1, 1, 1, 0, 1, 0, 0 },
                           { 1, 1, 0, 1, 0, 1, 1, 0 },
                           { 1, 1, 0, 1, 1, 1, 1, 0 },
                           { 1, 0, 1, 0, 0, 1, 0, 0 },
                           { 1, 1, 1, 1, 1, 1, 1, 0 },
                           { 1, 1, 1, 1, 0, 1, 1, 0 } };

void display(int startPin, int n) {
  for (int i = 0; i < 7; i++) {
    write(startPin, order[i], numbers[n][i] ? LOW : HIGH);
  }
}

void write(int startPin, int addr, boolean value) {
  digitalWrite(startPin, addr & 1 ? HIGH : LOW);
  digitalWrite(startPin - 1, addr & 2 ? HIGH : LOW);
  digitalWrite(startPin - 2, addr & 4 ? HIGH : LOW);
  digitalWrite(startPin - 4, value);
  digitalWrite(startPin - 3, LOW);
  digitalWrite(startPin - 3, HIGH);
}

void setup() {                
  for (int i = 3; i <= 13; i++) {
    pinMode(i, i == 8 ? INPUT : OUTPUT);
  }
}

int n = 0;

void loop() {
  if (digitalRead(8)) {
    n = (n + 1) % 6;
  }
  
  display(7, n + 2);
  display(13, n + 4);
  
  delay(100);
}
