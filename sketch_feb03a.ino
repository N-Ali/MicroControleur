const int buttonPin = 2;
const int ledPin = 7;
int buttonState = 0;
int state = HIGH; 

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  /*if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH); 
  }
  else{
    digitalWrite(ledPin, LOW); 
  }*/
  if(buttonState == LOW && state == LOW){
    digitalWrite(ledPin, HIGH);
    state = HIGH;
    while(buttonState != HIGH){
      buttonState = digitalRead(buttonPin);
      }
  }
  else if(buttonState == LOW && state == HIGH){
    digitalWrite(ledPin, LOW);
    state = LOW;
    while(buttonState != HIGH){
      buttonState = digitalRead(buttonPin);
      }
  }
  
}
