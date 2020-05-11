#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensorPin = 0; 
int buttonLaunch = 7;
bool launch = false;
int buttonMinute = 9;
int buttonHour = 10;

int hour = 00;
int minute = 00;
int seconde = 00;
 

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2); 
  pinMode(buttonLaunch, INPUT);
  pinMode(buttonMinute, INPUT);
  pinMode(buttonHour, INPUT);
}
 
void loop()                     
{
 
  lcd.clear();
  lcd.print("    ");
  
  //Button
  if(digitalRead(buttonMinute) == HIGH && launch == false){
    if(minute == 59)
      minute = 0;
    else
      minute++;
  }
  if(digitalRead(buttonHour) == HIGH && launch == false){
    if(hour == 24)
      hour = 0;
    else
      hour++;
  }
  if(digitalRead(buttonLaunch) == HIGH){
    launch = !launch;
  }
  
  
  if(hour < 10){
    lcd.print("0");
  }
  lcd.print(hour);
  lcd.print(":");
  if(minute < 10){
    lcd.print("0");
  }
  lcd.print(minute);
  lcd.print(":");
  if(seconde < 10){
    lcd.print("0");
  }
  lcd.print(seconde);
  
  if(launch == true){
    // Hour
    if(minute == 59 && seconde == 59){
      hour++;
    }
    if(hour == 24){
      hour = 0;
    }
    // Minute
    if(seconde == 59){
      minute++;
    }
    if(minute == 60){
      minute = 0;
    }
    // Seconde
    if(seconde == 59){
      seconde = 0;
    }
    else{
      seconde++;
    }
    
    //Temperature
    int reading = analogRead(sensorPin);  
    float voltage = reading * 5.0;
    voltage /= 1024.0; 
    float temperatureC = (voltage - 0.5) * 100 ; 
    //TemperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
    //lcd.print(temperatureF); 
    //lcd.println(" degrees F ");
    lcd.setCursor(0,1);
    lcd.print("     ");
    lcd.print(temperatureC);
    lcd.print("C");
    delay(1000);
  }
  
  else{
    delay(400);
  }
    
}

