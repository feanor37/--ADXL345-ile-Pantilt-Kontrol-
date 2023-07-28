#include <Wire.h>
#include <Servo.h>
-----------------------------------------------------


Lütfen Kodların Tamamı için İletişime Geçin

https://www.linkedin.com/in/nuh-kaan-gun-59172b248/

 ----------------------------------------------------

    z += (((int)buff[5]) << 8) | buff[4];
    delay(10);
  }
  
  x /= 5;
  y /= 5;
  z /= 5;
  
  if (x < -255)
    x = -255;
  else if (x > 255)
    x = 255;
  
  if (y < -255)
    y = -255;
  else if (y > 255)
    y = 255;
  
  x = map(x, -255, 255, 0, 180);
  y = map(y, -255, 255, 0, 180);
  
  myservox.write(x);
  delay(25);
  myservoy.write(180 - y);
  delay(25);
  
  delay(200);
}

void writeTo(int device, byte address, byte val) {
  Wire.beginTransmission(device);
  Wire.write(address);
  Wire.write(val);
  Wire.endTransmission();
}

void readFrom(int device, byte address, int num, byte buff[]) {
  Wire.beginTransmission(device);
  Wire.write(address);
  Wire.endTransmission();
  
  Wire.beginTransmission(device);
  Wire.requestFrom(device, num);
  
  int i = 0;
  while (Wire.available()) {
    buff[i] = Wire.read();
    i++;
  }
  
  Wire.endTransmission();
}
