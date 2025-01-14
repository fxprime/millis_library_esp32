#include "TickTwo.h"

void printMessage(); 

TickTwo timer(printMessage, 2000, 0, MICROS);


void checkStatus() {
  Serial.print("Timer state: ");
  switch(timer.state()) {
    case STOPPED:
      Serial.println("STOPPED");
      break;
    case RUNNING:
      Serial.println("RUNNING");
      break;
    case PAUSED:
      Serial.println("PAUSED");
      break;
  }
}

void setup() { 
  Serial.begin(115200);
  delay(2000);
  timer.start();
}

void loop() {
  timer.update();

  if(timer.counter() >= 5 && timer.interval() == 2000000) {
    Serial.println("Ran 5 times.. now change the interval to 1000ms");
    timer.stop();
    checkStatus();
    timer.interval(1000);
    timer.resume(); //หลัง stop จะนับ counter ใหม่
    checkStatus(); 
  }
  if(timer.counter() >= 5 && timer.interval() == 1000000) {
    Serial.println("Ran 5 times.. now change the interval to 500ms");
    timer.pause();
    checkStatus();
    timer.interval(500);
    timer.resume(); //หลัง pause จะไม่นับ counter ใหม่ 
    checkStatus();
  }
  if(timer.counter() >= 10 && timer.interval() == 500000) {
    Serial.println("Ran 5 times.. now stop the timer");
    timer.stop();
  }
}
 
 

void printMessage() {
  Serial.print("->");
  Serial.println(micros());
}
  