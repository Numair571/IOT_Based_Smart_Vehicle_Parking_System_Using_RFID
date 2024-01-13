#include <Servo.h>

int count = 0;
char card_no[12];
Servo myservo;

void setup() {
   Serial.begin(9600);
   myservo.attach(D8); /
}

void loop() {
   if (Serial.available()) {
      count = 0;
      while (Serial.available() && count < 12) {
         card_no[count] = Serial.read();
         count++;
         delay(5);
      }
      card_no[count] = '\0'; 
      Serial.print("Received Card ID: ");
      Serial.println(card_no);

     
      if (strcmp(card_no, "YOUR_PREDEFINED_CARD_ID") == 0) {
         openGate(); 
      } else {
         Serial.println("Access denied!"); 
      }
   }
}

void openGate() {
   Serial.println("Access granted");
   myservo.write(90);
   delay(5000); 
   myservo.write(0); 
   Serial.println("Gate closed");
}
