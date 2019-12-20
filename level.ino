
  #include <LiquidCrystal.h>
  LiquidCrystal lcd(8,9,4,5,6,7);
  byte sensorPin[] = {2,3,4};
  const byte sensors = 3; // sensor analog input from A2
  int level = 0; 
  int motor = A5;
  
  void setup() {
    for(int i = 0; i < sensors; i++) {
       pinMode(sensorPin[i], INPUT); 
    }
    pinMode(motor, OUTPUT);
    lcd.begin(16, 2);  
  }
  
  void loop() {
    level = 0; 
    for(int i = 0; i < sensors; i++) {
       if(digitalRead(sensorPin[i]) == LOW) {
          level = sensors - i;
       }    
    }
    lcd.clear();
    lcd.print("Water level");
    lcd.setCursor(0,1);  
    switch(level) {
       case 1:    lcd.print("HIGH");      digitalWrite(motor, LOW);  break;
       case 2:    lcd.print("AVERAGE");   digitalWrite(motor, HIGH);   break;
       case 3:    lcd.print("LOW");       digitalWrite(motor, HIGH);   break;
       default:   lcd.print("NO WATER");  digitalWrite(motor, HIGH);   break;
    }
    delay(5000);  
   }
   
