#include <Wire.h>
#include "BME280.h"

BME280 bme280;

// void setAdvData(BLEAdvertising *pAdvertising)
// {
//   bme280.get_sensor_data(&data);
//   Serial.printf("temp: %.1f, humid: %.1f, press: %.1f\r\n", data.temperature, data.humidity, data.pressure / 100);
//   uint16_t temp = (uint16_t)(data.temperature * 100);
//   uint16_t humid = (uint16_t)(data.humidity * 100);
//   uint16_t press = (uint16_t)(data.pressure / 10);

//   BLEAdvertisementData oAdvertisementData = BLEAdvertisementData();

//   oAdvertisementData.setFlags(0x06); // BR_EDR_NOT_SUPPORTED | LE General Discoverable Mode

//   std::string strServiceData = "";
//   strServiceData += (char)0x0a;   // 長さ
//   strServiceData += (char)0xff;   // AD Type 0xFF: Manufacturer specific data
//   strServiceData += (char)0xff;   // Test manufacture ID low byte
//   strServiceData += (char)0xff;   // Test manufacture ID high byte
//   strServiceData += (char)seq;                   // シーケンス番号
//   strServiceData += (char)(temp & 0xff);         // 温度の下位バイト
//   strServiceData += (char)((temp >> 8) & 0xff);  // 温度の上位バイト
//   strServiceData += (char)(humid & 0xff);        // 湿度の下位バイト
//   strServiceData += (char)((humid >> 8) & 0xff); // 湿度の上位バイト
//   strServiceData += (char)(press & 0xff);        // 気圧の下位バイト
//   strServiceData += (char)((press >> 8) & 0xff); // 気圧の上位バイト

//   oAdvertisementData.addData(strServiceData);
//   pAdvertising->setAdvertisementData(oAdvertisementData);
// }

void setup()
{
  //シリアル通信初期化
  Serial.begin(9600);//シリアル通信を9600bpsで初期化
  delay(1000);//1000msec待機(1秒待機)

  bme280.begin();
}

void loop()
{
  bme280.update();
  
  //シリアルモニタ送信
  Serial.print("Pressure:");//文字列「Pressure:」をシリアルモニタに送信
  Serial.print(bme280.readPressure());//「pres」をシリアルモニタに送信
  Serial.print("hPa ");//文字列「hPa 」をシリアルモニタに送信
  Serial.print("Temp:");//文字列「Temp:」をシリアルモニタに送信
  Serial.print(bme280.readTemperature());//「temp」をシリアルモニタに送信
  Serial.print("°C ");//文字列「°C 」をシリアルモニタに送信
  Serial.print("Humidity:");//文字列「Humidity:」をシリアルモニタに送信
  Serial.print(bme280.readHumidity());//「humi」をシリアルモニタに送信
  Serial.println("%");//文字列「%」をシリアルモニタに送信、改行
  
  delay(1000);//1000msec待機(1秒待機)
}
