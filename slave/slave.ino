// Slave
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

int connected_pins[] = {A0, A1, A2, A3, A4};
int connected_pins_size = sizeof(connected_pins) / sizeof(connected_pins[0]);

void setup()
{
  Serial.begin(9600);
  while (!Serial) {}
  Serial.println("Check!");
  mySerial.begin(4800);
}

void loop()
{
  String data = "";
  for (int i = 0; i < connected_pins_size; i++)
  {
    data += (String)connected_pins[i] + " ";
  }
  data += "\n";
  Serial.println("debug:\n" + data);
  mySerial.write(data.c_str());
  delay(1000);
}