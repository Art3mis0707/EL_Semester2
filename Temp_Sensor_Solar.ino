#include <Adafruit_MLX90614.h>
#include <Servo.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
Servo myservo;

int buzzer_Pin = 11;

void setup() {
  myservo.attach(9);
  pinMode(buzzer_Pin, OUTPUT);  
  myservo.write(25);
  mlx.begin();
  delay(7000);
}

void loop() {
  digitalWrite(11,LOW);
  float temperature = mlx.readObjectTempF();
  if (temperature>91)
  {
    digitalWrite(11, HIGH);
  }

  if (temperature<91 && temperature>89)
  {
    myservo.write(100); 
    delay(5000);
    myservo.write(25);
    delay(5000);
  }
}

