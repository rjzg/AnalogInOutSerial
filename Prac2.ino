void setup() {            
  Serial.begin(9600);   
  pinMode(13, OUTPUT); // led
  pinMode(10, OUTPUT); // led
  pinMode(A0, INPUT); // ldr
}

double Thermister(int RawADC) {  
 double Temp;
 Temp = log(((10240000/RawADC) - 10000));
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;              
 //Temp = (Temp * 9.0)/ 5.0 + 32.0; // Celsius to Fahrenheit - comment out this line if you need Celsius
 return Temp; // in faren
}

void loop() {             
  int val;                
  double temp;            
  val=analogRead(0);      
  
  temp=Thermister(val);   
  Serial.print("temp = ");
  Serial.println(temp);   
  
  int pow1 = map(temp, 0, 23, 0, 255);
  Serial.print("power1 = ");
  Serial.println(pow1);
  digitalWrite(10, pow1);

  int ldrStatus = analogRead(A0);
  Serial.print("light = ");
  Serial.println(ldrStatus); 
  
  int pow2 = map(ldrStatus, 125, 1023, 0 , 255);
  Serial.print("power2 = ");
  Serial.println(pow2);
  digitalWrite(13, pow2);

  Serial.println("");
  delay(1000);            

}
