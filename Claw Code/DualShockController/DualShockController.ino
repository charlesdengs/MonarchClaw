#include <DualShock4Controller.h>
#include <KeyboardController.h>
#include <MouseController.h>
#include <Usb.h>
#include <address.h>
#include <adk.h>
#include <confdescparser.h>
#include <hid.h>
#include <hidboot.h>
#include <hidusagestr.h>
#include <parsetools.h>
#include <usb_ch9.h>



USBHost usb;
DualShock4Controller dualshock(usb);

void buttonPressed(uint16_t buttons)
{
  if (buttons & X)
  {
    Serial.println("X button pressed");
  }
  if (buttons & R2)
  {
    Serial.println("Right trigger pressed");
  }
  if (buttons & PS)
  {
    Serial.println("PlayStation button pressed");
  }
}

void buttonReleased(uint16_t buttons)
{
  if (buttons & X)
  {
    Serial.println("X button released");
  }
  if (buttons & R2)
  {
    Serial.println("Right trigger released");
  }
  if (buttons & PS)
  {
    Serial.println("PlayStation button released");
  }
}

void setup()
{
  dualshock.setAxisDeadzone(15);

  Serial.begin(115200);
  Serial.println("Program started");
  delay(200);
}

void loop()
{
  usb.Task();

}