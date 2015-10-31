int pushButton = 12;
int led = 13;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  pinMode(led, OUTPUT);
}

int prevState = 0;
int counter = 0;

int is_prime(int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

void loop() {
  int buttonState = digitalRead(pushButton);
  
  if (buttonState != prevState && buttonState) {
    counter++;
    Serial.println(counter);
    digitalWrite(led, is_prime(counter));
  }
  
  prevState = buttonState;
  // this delay is sufficient to avoid the switch "bouncing" registering as multiple presses:
  delay(10);
}



