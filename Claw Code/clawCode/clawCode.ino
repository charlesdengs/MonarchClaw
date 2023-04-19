#include <Servo.h>

#include <DualShock4Controller.h>

USBHost usb;
DualShock4Controller dualshock(usb);

//Servo position variable
int servoPosition = -46;

//Create servo
Servo clawServo;


void openCloseClaw() {
  if (dualshock.state.l2 and !dualshock.state.r2 and servoPosition >= -90)
  {
    servoPosition -= 1;


  }
  if (dualshock.state.r2 and !dualshock.state.l2 and servoPosition <= 45)
  {
    servoPosition += 1;

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
  openCloseClaw();
  Serial.println(servoPosition);
  clawServo.write(servoPosition);


}
