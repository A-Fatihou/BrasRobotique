// PROJET BRAS ROBOTIQUE ADAMOU FATIHOU

#include <SoftwareSerial.h> //  Bibliothèque logicielle TX RX pour Bluetooth

#include <Servo.h> // servo library 
Servo myservo1, myservo2, myservo3, myservo4; // Le nom des moteur 

int bluetoothTx = 10; // bluetooth tx connecté au  10 pin
int bluetoothRx = 11; // bluetooth rx connecté au  11 pin

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  myservo1.attach(3); // attachez le fil du signal du servo à la broche 9
  myservo2.attach(5);
  myservo3.attach(6);
  myservo4.attach(9);
  //Setup connexion série usb à l'ordinateur
  Serial.begin(9600);

  //Configuration de la connexion série Bluetooth pour android
  bluetooth.begin(9600);
}

void loop()
{
  //Lecture depuis Bluetooth et écriture sur USB série
  if(bluetooth.available()>= 2 )
  {
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 *256) + servopos;
    Serial.println(realservo);

    if (realservo >= 1000 && realservo <1180) {
      int servo1 = realservo;
      servo1 = map(servo1, 1000, 1180, 0, 180);  // Le sense de rotation 
      myservo1.write(servo1);
      Serial.println("Servo 1 ON"); // Affiche dans le moniteur en serie l'etat du moteur 
      delay(10);
    }
    if (realservo >= 2000 && realservo <2180) {
      int servo2 = realservo;
      servo2 = map(servo2, 2000, 2180, 0, 180);
      myservo2.write(servo2);
      Serial.println("Servo 2 ON");
      delay(10);
    }
    if (realservo >= 3000 && realservo <3180) {
      int servo3 = realservo;
      servo3 = map(servo3, 3000, 3180, 0, 180);
      myservo3.write(servo3);
      Serial.println("Servo 3 ON");
      delay(10);
    }
    if (realservo >= 4000 && realservo <4180) {
      int servo4 = realservo;
      servo4 = map(servo4, 4000, 4180, 0, 180);
      myservo4.write(servo4);
      Serial.println("Servo 4 ON");
      delay(10);
    }
  }
}