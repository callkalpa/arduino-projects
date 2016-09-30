const int pirPin = 8;
const int ledPin = 13;

long time;
boolean stateChanged;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
  while(!Serial);
  Serial.println('Serial is ready!');
}

void loop() {
  int sensorValue = digitalRead(pirPin);

  if(sensorValue == HIGH) {
    digitalWrite(ledPin, HIGH);
    if(stateChanged == false) {
      stateChanged = true;
      time = millis();
    }
  } else {
    if (stateChanged) {
      Serial.println(millis() - time);
      stateChanged = false;
    }
    digitalWrite(ledPin, LOW);
  }

}
