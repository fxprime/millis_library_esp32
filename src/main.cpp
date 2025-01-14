#include "TickTwo.h"

void printMessage(); 

TickTwo timer(printMessage, 1000, 0, MICROS);


void setup() { 
  Serial.begin(115200);
  delay(2000);
  timer.start();
}

void loop() {
  timer.update();

  if(timer.counter() > 5) {
    Serial.println("Ran 5 times.. now change the interval to 500ms");
    timer.stop();
    timer.interval(500);
    timer.resume(); //นับ counter ใหม่
  }
}
 
 

void printMessage() {
  Serial.println("Hello World");
}
  