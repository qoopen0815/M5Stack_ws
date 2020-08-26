// #include <M5Stack.h>
#include <Wire.h>
#include "BME280.h"
#include "BLE_broadcaster.h"

BME280 bme280;
BLEBroadcaster ble("M5Stack");

void setup()
{
  //シリアル通信初期化
  Serial.begin(9600);   //シリアル通信を9600bpsで初期化
  delay(1000);          //1000msec待機(1秒待機)

  bme280.begin();
}

void loop()
{
  bme280.update();
  
  // シリアルモニタ送信
  // Serial.print("Pressure:");              //文字列「Pressure:」をシリアルモニタに送信
  // Serial.print(bme280.readPressure());    //「pres」をシリアルモニタに送信
  // Serial.print("hPa ");                   //文字列「hPa」をシリアルモニタに送信
  // Serial.print("Temp:");                  //文字列「Temp:」をシリアルモニタに送信
  // Serial.print(bme280.readTemperature()); //「temp」をシリアルモニタに送信
  // Serial.print("°C ");                    //文字列「°C 」をシリアルモニタに送信
  // Serial.print("Humidity:");              //文字列「Humidity:」をシリアルモニタに送信
  // Serial.print(bme280.readHumidity());    //「humi」をシリアルモニタに送信
  // Serial.println("%");                    //文字列「%」をシリアルモニタに送信、改行

  delay(1000);  //1000msec待機(1秒待機)
}
