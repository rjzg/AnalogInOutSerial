void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(7, OUTPUT);
  }

void loop() {
  int sensorValue = analogRead(A0);
  int f = map(sensorValue,0,1023,10000,1000);
  
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.println();
    
  Serial.print("frequency = ");
  Serial.print(f);
  Serial.println();

  
  if(sensorValue> 1000){
    digitalWrite(7 ,HIGH);
    noTone(3);
      }else {
        digitalWrite(7, LOW); 
        tone(3,f);
      
   delay(2);
  }
}
