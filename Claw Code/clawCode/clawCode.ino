#include <Servo.h>

#include <DualShock4Controller.h>

USBHost usb;
DualShock4Controller dualshock(usb);

//Servo position variable
int servoPosition = -46;

//Create servo
Servo clawServo;


void openCloseClaw() {
  if ((dualshock.state.analogL2 == 255) and (dualshock.state.analogR2 == 0) and (servoPosition >= -90))
  {
    servoPosition -= 1;
    Serial.print(dualshock.state.analogL2);
  }
  if ((dualshock.state.analogL2 == 0) and (dualshock.state.analogR2 == 255) and (servoPosition <= 45))
  {
    servoPosition += 1;
    Serial.print(dualshock.state.analogR2);
  }
  clawServo.write(servoPosition);
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
  openCloseClaw();
  Serial.println(servoPosition);

}
