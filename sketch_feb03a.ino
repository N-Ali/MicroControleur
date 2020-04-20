/* Arduino tutorial - Buzzer / Piezo Speaker
   More info and circuit: http://www.ardumotive.com/how-to-use-a-buzzer-en.html
   Dev: Michalis Vasilakis // Date: 9/6/2015 // www.ardumotive.com */


const int buzzer = 9; //buzzer to arduino pin 9
const int led = 7;
const int button = 2;
int buttonState = 0;

int data;


void setup(){
 
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(led,OUTPUT);
  pinMode(button,INPUT_PULLUP);
  Serial.begin(9600);
  //digitalWrite(led,HIGH);
}

void loop(){

  buttonState = digitalRead(button);
  if(buttonState ==LOW){
    digitalWrite(led, HIGH);
    tone(buzzer, 1000);
    }
    
  else {
    digitalWrite(led, LOW);
     noTone(buzzer);
   
  }
  
}
