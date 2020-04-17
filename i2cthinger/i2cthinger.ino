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
  byte val1 = byte(analogRead(0)-(700));
  byte val2 = byte(analogRead(1)-(700));
  byte val3 = byte(analogRead(2) -(700));
  byte val4 = byte(analogRead(3) - (700));
  Wire.write(map(val1,0,323,0,255));
  Wire.write(map(val2,0,323,0,255));
  Wire.write(map(val3,0,323,0,255));
  Wire.write(map(val4,0,323,0,255));
//  Wire.endTransmission();

  //sendFlag = true;
}

