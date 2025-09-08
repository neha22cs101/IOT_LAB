const int sensorPin = A0;        
const int ledPin = 13;           
int sensorValue = 0;             
int threshold = 600; 
int dry=800;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);          
}

void loop() {
  sensorValue = analogRead(sensorPin);  
  Serial.print("Soil moisture sensor value: ");
  Serial.println(sensorValue);

 
  if (sensorValue >=dry) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Soil is dry");
  }
    else if(sensorValue>=threshold && sensorValue<dry){
     digitalWrite(ledPin, LOW); 
      Serial.println("Soil is moderate");
    
  } else {
    digitalWrite(ledPin, LOW);    
      Serial.println("Soil is extremely wet");
  }

  delay(1000); 
}
