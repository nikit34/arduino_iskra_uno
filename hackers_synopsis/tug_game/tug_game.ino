#define BUZZOR_PIN 0
#define FIRST_BAR_PIN 4
#define BAR_COUNT 10
#define MAX_SCORE 20


volatile int score = 0;

void setup() {
    for (int i = 0; i < BAR_COUNT; ++i)
        pinMode(i + FIRST_BAR_PIN, OUTPUT);
    pinMode(BUZZOR_PIN, OUTPUT);
    attachInterrupt(1, pushP1, FALLING);
    attachInterrupt(0, pushP2, FALLING);
}

void pushP1() { ++score; };
void pushP2() { --score; };

void loop() {
    tone(BUZZOR_PIN, 2000, 1000);

    while(abs(score) < MAX_SCORE) {
        int bound = map(score, -MAX_SCORE, MAX_SCORE, 0, BAR_COUNT);
        int left = min(bound, BAR_COUNT / 2 - 1);
        int right = max(bound, BAR_COUNT / 2);
        for (int i = 0; i < BAR_COUNT; ++i)
            digitalWrite(i + FIRST_BAR_PIN, i >= left && i <= right);
    }
    tone(BUZZOR_PIN, 4000, 1000);
    while (true) {}
}