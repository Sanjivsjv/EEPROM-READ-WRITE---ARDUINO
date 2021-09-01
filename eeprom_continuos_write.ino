#include <EEPROM.h>
int addr = 0;
int i=0;
int data;

void setup() 
{
    EEPROM.begin(512);
    Serial.begin(9600);
    
}

void loop()
{  

      //Serial.println(i);
      if(i <= 255)
      {
               EEPROM.write(addr,i);
               data = EEPROM.read(addr);
               Serial.println(data);
               addr++;
      }

            else if((i > 256)&&(i<510))
      {
               Serial.println("*******************************");

               int a=i/256;
               int z=i%256;
               Serial.println(addr);
               EEPROM.write(addr,a);
               addr++;
               Serial.println(addr);
               EEPROM.write(addr,z);
               addr--; 
               Serial.println(addr);
               data = EEPROM.read(addr)+255;
               addr++;
               Serial.println(addr);
               data = data*EEPROM.read(addr);
               addr++;
               
               Serial.println(data);
               Serial.print("*******************************");
               delay(2000);
               
             
               
      }
//      else if((i > 255)&&(i<510))
//      {
//               Serial.println("welcome");
//               EEPROM.write(i%255,addr);
//               addr+=1;
//               EEPROM.write(255,addr);
//               addr-=1;
//               data = EEPROM.read(addr);
//               addr+=1;
//               data = data+(EEPROM.read(addr));
//               Serial.println(data);
//               addr++;
//      }
      Serial.println(i);
      i++;
}
