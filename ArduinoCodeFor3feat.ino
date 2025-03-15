#include <SoftwareSerial.h>

SoftwareSerial BT(2, 3); // RX, TX for HC-05

int led1 = 9;   // LED1 PWM pin
int led2 = 10;  // LED2 PWM pin
int led3 = 11;  // LED3 PWM pin

int brightnessLow = 50;   // Low intensity (0-255)
int brightnessHigh = 255; // High intensity (0-255)

void setup() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    
    analogWrite(led1, brightnessLow);
    analogWrite(led2, brightnessLow);
    analogWrite(led3, brightnessLow);

    BT.begin(9600);
}

void loop() {
    if (BT.available()) {
        char command = BT.read();

        if (command == '1') { // Turn off LED1, others max
            analogWrite(led1, 0);
            analogWrite(led2, brightnessHigh);
            analogWrite(led3, brightnessHigh);
        } 
        else if (command == '2') { // Turn off LED2, others max
            analogWrite(led1, brightnessHigh);
            analogWrite(led2, 0);
            analogWrite(led3, brightnessHigh);
        } 
        else if (command == '3') { // Turn off LED3, others max
            analogWrite(led1, brightnessHigh);
            analogWrite(led2, brightnessHigh);
            analogWrite(led3, 0);
        } 
        else if (command == 'R') { // Reset to low brightness
            analogWrite(led1, brightnessLow);
            analogWrite(led2, brightnessLow);
            analogWrite(led3, brightnessLow);
        }
    }
}