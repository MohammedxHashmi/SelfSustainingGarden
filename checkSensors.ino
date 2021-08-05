// Sensor pins
// #define sensorPin A0
#define numSensors 6
#define numAnalog 5
#define digitalSensor 7


// Value for storing water level
int values[numSensors];
void setup() {
  // Set D7 as an OUTPUT
  for (int i = 1; i <= numSensors; i++) {
    pinMode(i, OUTPUT);
    // Set to LOW so no power flows through the sensor
    digitalWrite(i, LOW);
  }
  pinMode(8, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {
  //get the reading from the function below and print it
  readSensors();
  for (int i = 0; i < numAnalog; i++) {
    Serial.print("Water level: ");
    Serial.println(values[0]);
    if (values[0] > 400) {
      digitalWrite(8, HIGH);
    } else {
      digitalWrite(8, LOW);
    }

  }
    
  delay(1000);
}

//This is a function used to get the reading
void readSensors() {
  for (int i = 14; i < 14 + numAnalog; i++) {
    Serial.print("Testing sensor: ");
    Serial.println(i-13);
    digitalWrite(i, HIGH);  // Turn the sensor ON
    delay(10);              // wait 10 milliseconds
    values[i-14] = analogRead(i);    // Read the analog value form sensor
    
    digitalWrite(i, LOW);   // Turn the sensor OFF
    delay(500);
  }
  values[5] = digitalRead(digitalSensor);
  
}