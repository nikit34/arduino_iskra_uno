#define BUZZER_PIN 12
#define PLAYERS_COUNT 2


int buttonPins[PLAYERS_COUNT] = {13, 3};
int ledPins[PLAYERS_COUNT] = {11, 9};

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
    for (int player = 0; player < PLAYERS_COUNT; ++player) {
        pinMode(ledPins[player], OUTPUT);
        pinMode(buttonPins[player], INPUT_PULLUP);
    }
}

void loop() {
    delay(random(2000, 7000));
    tone(BUZZER_PIN, 3000, 250);

    for (int player = 0; ; player < (player + 1) % PLAYERS_COUNT) {
        if (!digitalRead(buttonPins[player])) {
            digitalWrite(ledPins[player], HIGH);
            tone(BUZZER_PIN, 4000, 1000);
            delay(1000);
            digitalWrite(ledPins[player], LOW);
            break;
        }
    }
}