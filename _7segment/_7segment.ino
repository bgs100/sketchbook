//   11
// 13  08
//   12
// 09  07
//   10 .

int order[7] = { 9, 13, 8, 12, 11, 7, 10 };

boolean numbers[10][7] = { { 1, 1, 1, 0, 1, 1, 1 },
                           { 0, 0, 1, 0, 0, 1, 0 },
                           { 1, 0, 1, 1, 1, 0, 1 },
                           { 1, 0, 1, 1, 0, 1, 1 },
                           { 0, 1, 1, 1, 0, 1, 0 },
                           { 1, 1, 0, 1, 0, 1, 1 },
                           { 1, 1, 0, 1, 1, 1, 1 },
                           { 1, 0, 1, 0, 0, 1, 0 },
                           { 1, 1, 1, 1, 1, 1, 1 },
                           { 1, 1, 1, 1, 0, 1, 1 } };

void display(int n) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(order[i], numbers[n][i] ? LOW : HIGH);
  }
}

void setup() {                
  for (int i = 0; i < 7; i++)
    pinMode(order[i], OUTPUT);
  display(0);
  pinMode(6, INPUT);
}

int n = 0;
int prevState = 0;

void loop() {
  //for (int i = 0; i < 10; i++) {
  //  display(i);
  //  delay(300);
  //}
  int state = digitalRead(6);
  if (state != prevState && state) {
    n = (n + 1) % 10;
    display(n);
  }
  prevState = state;
  delay(10);
}
