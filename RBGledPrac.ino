const int analogInPin = A0;
const int analogInPin2 = A1;
const int analogInPin3 = A2;     
const int analogOutPin = 9;
const int analogOutPin2 = 10;
const int analogOutPin3 = 11;   
int sensorValue = 0;   
int sensorValue2 = 0; 
int sensorValue3 = 0;                
int outputValue = 0;
int outputValue2 = 0;
int outputValue3 = 0;         

void setup() {

  Serial.begin(9600);
  
}

void loop() {
  
  //BLUE LED
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(analogOutPin, outputValue);

  Serial.print("BLUE");
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  //GREEN LED
  sensorValue2 = analogRead(analogInPin2);
  outputValue2 = map(sensorValue2, 0, 1023, 0, 255);
  analogWrite(analogOutPin2, outputValue2);

  Serial.print("GREEN");
  Serial.print("sensor = ");
  Serial.print(sensorValue2);
  Serial.print("\t output = ");
  Serial.println(outputValue2);
  
  //RED LED
  /*sensorValue3 = analogRead(analogInPin3);
  outputValue3 = map(sensorValue2, 0, 1023, 0, 255);
  analogWrite(analogOutPin3, outputValue3);

  Serial.print("RED");
  Serial.print("sensor = ");
  Serial.print(sensorValue3);
  Serial.print("\t output = ");
  Serial.println(outputValue3);*/
  
  Serial.println("");
  delay(1000);
}
