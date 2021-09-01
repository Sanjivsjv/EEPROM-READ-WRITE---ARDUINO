#include <EEPROM.h>
int addr = 0;
int i=0;
int data,data1;

void setup() 
{
    EEPROM.begin(4000);
    Serial.begin(9600);
    
}

void loop()
{  

       
        int z = i%256;
        int y = i/256;
        
        EEPROM.write(addr,y);
        addr++;
        EEPROM.write(addr,z);
        addr--;  
        data = EEPROM.read(addr);
        //Serial.println(data);

        addr++;
        data1 = EEPROM.read(addr);
        //Serial.println(data1);

        if(data == 0)
        {
          data = data1;
        }
        else
        {
          data=data*256+data1;
        }
        
        Serial.println(data);
        //delay(500);
        addr++;
        i++;
       if(addr > 4000)
        {
          Serial.println("write successfully");
          int data3 = EEPROM.read(3998);
          int data4 = EEPROM.read(3999);
          int data5=data3*256+data4;
          Serial.print(data5);
          delay(10000);
        }
}
