#include <LiquidCrystal.h>
#include <Servo.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

Servo myservo;  // create servo object to control a servo


const int buzzer_Pin = 11;
char face_status = 0;

void setup() {  
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(buzzer_Pin, OUTPUT);  
  myservo.write(25);
  mlx.begin();
}
void loop() { 
  digitalWrite(buzzer_Pin, LOW); 
  while (Serial.available() > 0) 
  {
    face_status = Serial.read();
    if(face_status == 'b')
    {
      for (int x = 0 ; x<5 ; x++)
      {
          digitalWrite(buzzer_Pin, HIGH);
          delay(100);
          digitalWrite(buzzer_Pin, LOW);
      }
    }

    else if(face_status == 'a')
    { 
      float temperature = mlx.readObjectTempF();
      if (temperature>92.5)
      {
        digitalWrite(11, HIGH);
      }

      if (temperature<92.5 && temperature>89)
      {
        myservo.write(100); 
        delay(5000);
        myservo.write(25);
        delay(7000);
      }
   }
 } 
}  
