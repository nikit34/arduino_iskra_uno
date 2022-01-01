int switchPin = 8;
int ledPin = 13;
boolean lastBtn = LOW;
boolean currentBtn = LOW;
boolean led0n = false;

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

boolean debounce(boolean last){
  boolean current = digitalRead(switchPin);
  if (last != current) {
    delay(5);
    current = digitalRead(switchPin);
  }
  return current;
}

void loop() {
  currentBtn = debounce(lastBtn);
  if (lastBtn == LOW && currentBtn == HIGH){
    led0n = !led0n;
  }
  lastBtn = currentBtn;
  digitalWrite(ledPin, led0n);
}