#include "Motor.h"
Motor motor(13,14,27,4);
const int Sensor_PinD = 33;
const int Sensor_PinE = 32;



void setup() {
  // Begin
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  // cpnfigure the pins
  pinMode(Sensor_PinE, INPUT);
  pinMode(Sensor_PinD, INPUT);

  //Begin Motors
  motor.begin();
  motor.sound_vol(12);

   // bipa
  motor.bip(5,200,2000);



}

void loop() {
  
  Serial.println(digitalRead(Sensor_PinE));
  Serial.println(digitalRead(Sensor_PinD));
  
   if ((digitalRead(Sensor_PinE)==HIGH) && (digitalRead(Sensor_PinD)==LOW)) {
    Serial.println("virando pra direita");
     motor.move(550,550);
    }
    if ((digitalRead(Sensor_PinE)==LOW) && (digitalRead(Sensor_PinD)==HIGH)){
      Serial.println("virando para esquerda");
       motor.move(-550,-550);
    }
    if ((digitalRead(Sensor_PinE)==HIGH) && (digitalRead(Sensor_PinD)==HIGH)){
      Serial.println("procurando alvo");
       motor.move(550,550);
      }
    if ((digitalRead(Sensor_PinE)==LOW) && (digitalRead(Sensor_PinD)==LOW))  {
      Serial.println("te acheii");
       motor.stop();

    }
                                
                                                
  delay(10); // this speeds up the simulation
}
