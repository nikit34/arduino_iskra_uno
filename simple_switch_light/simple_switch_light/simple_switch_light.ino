int switchPin = 8;
int ledPin = 13; 
boolean lastBtn = LOW;
boolean led0n = false;

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(switchPin) == HIGH && lastBtn == LOW){
    led0n = !led0n;
    lastBtn = HIGH;   
  } else {
    lastBtn = digitalRead(switchPin);
  }
  digitalWrite(ledPin, led0n);
}
