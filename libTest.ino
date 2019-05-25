#include <Scheduler.h>
  Scheduler sched;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
delay(100);
  sched.addTask(hello)->withInterval(300)->withRepeatCount(3);
  sched.addTask(hello)->withInterval(300)->withRepeatCount(5);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Serial.println("run");
  sched.run();
}

void hello(){
  delay(1000);
  Serial.println("Hello world");
}
