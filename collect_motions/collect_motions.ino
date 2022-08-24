
#include <M5Core2.h>

#define FRONT 2

#define X_LOCAL 0
#define Y_LOCAL 0
#define X_OFFSET 160
#define Y_OFFSET 34

// 加速度のみ使用
float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;

void setup()
{
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.setTextFont(4);
  M5.Lcd.setTextColor(TFT_WHITE,TFT_BLACK);
  Serial.begin( 115200 );
}

void loop()
{
  // 内臓IMUから取得
  char buf[150];
  
  M5.IMU.getAccelData(&accX,&accY,&accZ);
  M5.Lcd.setCursor(X_LOCAL, Y_LOCAL + Y_OFFSET*4 , FRONT);
  sprintf(buf, " %5.3f   %5.3f   %5.3f   ", accX, accY, accZ);
  Serial.print(buf);
  M5.Lcd.printf(buf);
  delay(1000);
}