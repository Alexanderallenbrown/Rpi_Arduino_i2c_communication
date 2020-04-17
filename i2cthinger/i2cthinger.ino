
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
  byte val1 = byte(analogRead(0)-(1023-255));
  byte val2 = byte(analogRead(1)-(1023-255));
  byte val3 = byte(analogRead(2) -(1023-255));
  byte val4 = byte(analogRead(3) - (1023-255));
  
  Wire.write(val1);
  Wire.write(val2);
  Wire.write(val3);
  Wire.write(val4);

  //sendFlag = true;
}

