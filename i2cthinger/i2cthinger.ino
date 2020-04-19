#include <Wire.h>


int Address = 100;

bool receiveFlag = false;
bool sendFlag = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

 Wire.begin(Address);
 Wire.onRequest(requestEvent);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(analogRead(0));
delay(1);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent()
{
  byte val1 = byte(map(analogRead(0)-(750),0,323,0,255));
  byte val2 = byte(map(analogRead(1)-(750),0,323,0,255));
  byte val3 = byte(map(analogRead(2)-(750),0,323,0,255));
  byte val4 = byte(map(analogRead(3)-(750),0,323,0,255));
  Wire.write(val1);
  Wire.write(val2);
  Wire.write(val3);
  Wire.write(val4);
//  Wire.endTransmission();

  //sendFlag = true;
}

