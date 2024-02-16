 #include "LiquidCrystal.h"  
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2); % sets the connection pins from the arduino
 int Contrast = 75;% contrast setting needed due to no potentiometer 
 int irPin=13;  % IR input pin
 int count=0;  % Initializes count value 
 boolean state = true;  
 void setup()  
 {  
  analogWrite(6,Contrast);% sets contrast of the text and background on the LCD screen
  Serial.begin(9600);  
  lcd.begin(16,2);  % Inputs the LCD dimensions
  pinMode(irPin, INPUT);  % sets input value
  lcd.setCursor(0,0);  % positions Count No:
  lcd.print("Count No : ");  % prints count No: on screen
 }  
 void loop()  
 {  
  % Increases count & prints value if IR is disrupted  
  if (!digitalRead(irPin) && state){  
    count++;  
    state = false;  
    Serial.print("Count: ");  %serial prints count:
    Serial.println(count);  %serial prints count value
    lcd.setCursor(12,0);  %positions counts value on screen
    lcd.print(count);  %prints counted value
    delay(100);  
  }  
  if (digitalRead(irPin))  
  {  
    state = true;  % no interruption of IR sensor prints nothing
    delay(100);  
  }  
 }  
