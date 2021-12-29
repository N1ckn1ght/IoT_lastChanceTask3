// Master
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

int connected_pins[] = {A0, A1, A2, A3, A4};
int connected_pins_size = sizeof(connected_pins) / sizeof(connected_pins[0]);

void setup()
{
  Serial.begin(19200);
  while (!Serial) {}
  Serial.println("Check!");
  mySerial.begin(4800);
}

void loop()
{
  if (mySerial.available())
  {
    String sdata = "";
    int current_byte = 0;
    
    Serial.println("Master photoresistors:");
    for (int i = 0; i < connected_pins_size; i++)
    {
      Serial.print((String)analogRead(connected_pins[i]) + " ");
    }
    
    Serial.println("\nSlave photoresistors:");
    while (true)
    {
      while (mySerial.available())
      {
        sdata += (char)mySerial.read();
        if (sdata[current_byte] == '\n')
        {
          break;
        }
        current_byte++;
      }
      if (sdata[current_byte] != '\n')
      {
        delay(10);
      }
      else
      {
        break; 
      }
    }
    Serial.println(sdata);
  }
  else
  {
    Serial.println("Master photoresistors:");
    for (int i = 0; i < connected_pins_size; i++)
    {
      Serial.print((String)analogRead(connected_pins[i]) + " ");
    }
    Serial.println("\nSlave didn't provide any data yet.\n");
  }
  delay(1000);
}
