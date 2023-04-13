#include <Servo.h>

#include <DualShock4Controller.h>

USBHost usb;
DualShock4Controller dualshock(usb);

//Servo position variable
int servoPosition = 90;

//Create servo
Servo clawServo;

//Adds angles to open the claw when R1 held
void r1Pressed(uint16_t buttons)
{
  if (buttons & R1)
  {
    Serial.println("R1 Pressed");
    servoPosition += 5;
  }

}

void r1Released(uint16_t buttons)
{
  if (buttons & R1)
  {
    Serial.println("R1 Released");
  }
}

//Adds angles to close claw when L1 held
void l1Pressed(uint16_t buttons)
{
  if (buttons & L1)
  {
    Serial.println("L1 Pressed");
    servoPosition -= 5;
  }
}

void l1Released(uint16_t buttons)
{
  if (buttons & L1)
  {
    Serial.println("L1 Released");
  }
}

void setup() {
  // put your setup code here, to run once:
  dualshock.setAxisDeadzone(15);

  Serial.begin(115200);
  clawServo.attach(9);
  Serial.println("Program started");
  delay(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  usb.Task();
  clawServo.write(servoPosition);
  

}
