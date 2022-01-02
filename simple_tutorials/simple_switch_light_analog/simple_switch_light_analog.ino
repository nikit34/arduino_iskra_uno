int switchPin = 8;
int ledPin = 13; 
boolean lastBtn = LOW;
boolean currentBtn = LOW;
int ledLevel = 0;

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
    ledLevel = ledLevel + 51;
  }
  lastBtn = currentBtn;
  if (ledLevel > 255) {
    ledLevel = 0;
  }
  analogWrite(ledPin, ledLevel);
}
