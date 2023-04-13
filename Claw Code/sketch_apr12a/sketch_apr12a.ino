#include <Servo.h>

#include <MouseController.h>

USBHost usb;
MouseController mouse(usb);
int angle = 0;
Servo myservo;
void mousePressed() {
  Serial.print("Pressed: ");
  if (mouse.getButton(LEFT_BUTTON)) {
    Serial.print("L");
    Serial.println();
    angle += 5;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
  Serial.println("Program started");
  delay(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  usb.Task();
  myservo.write(angle);
  Serial.print(angle);
  Serial.println();
}
