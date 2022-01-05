#include <math.h>


int sec = 1;

void setup() {
    Serial.begin(9600);
    Serial.println("Secund\ttemperature: ");
}

void loop() {
    float voltage = analogRead(A0) * 5.0 / 1023.0;
    float temperature = -14.46 * log(voltage * 10000.0) / (5.0 - voltage) / 27074.0;

    Serial.println(String(sec) + "\t" + String(temperature));
    delay(1000);
    ++sec;
}