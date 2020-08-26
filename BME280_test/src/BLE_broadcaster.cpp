#include "BLE_broadcaster.h"
// #include "BME280.h"
#include <Wire.h>

BLEBroadcaster::BLEBroadcaster(const std::string name)
{
  BLEDevice::init(name);  // デバイスを初期化
  pServer_ = BLEDevice::createServer();
  pAdvertising_ = pServer_->getAdvertising();
}

BLEBroadcaster::~BLEBroadcaster()
{
}

void BLEBroadcaster::setAdvData(const BLEAdvertising *pAdvertising)
{
  // bme280.getSensorData(data);
  uint16_t temp = (uint16_t)(100 * 100);
  uint16_t humid = (uint16_t)(100 * 100);
  uint16_t press = (uint16_t)(100 / 10);

  BLEAdvertisementData oAdvertisementData = BLEAdvertisementData();

  oAdvertisementData.setFlags(0x06); // BR_EDR_NOT_SUPPORTED | LE General Discoverable Mode

  std::string strServiceData = "";
  strServiceData += (char)0x0a;   // 長さ
  strServiceData += (char)0xff;   // AD Type 0xFF: Manufacturer specific data
  strServiceData += (char)0xff;   // Test manufacture ID low byte
  strServiceData += (char)0xff;   // Test manufacture ID high byte
  strServiceData += (char)seq_;                   // シーケンス番号
  strServiceData += (char)(temp & 0xff);         // 温度の下位バイト
  strServiceData += (char)((temp >> 8) & 0xff);  // 温度の上位バイト
  strServiceData += (char)(humid & 0xff);        // 湿度の下位バイト
  strServiceData += (char)((humid >> 8) & 0xff); // 湿度の上位バイト
  strServiceData += (char)(press & 0xff);        // 気圧の下位バイト
  strServiceData += (char)((press >> 8) & 0xff); // 気圧の上位バイト

  oAdvertisementData.addData(strServiceData);
  pAdvertising_->setAdvertisementData(oAdvertisementData);

  seq_++;
}

void BLEBroadcaster::advertise(const int advertise_time)
{
  pAdvertising_->start();               // アドバタイズ起動
  delay(advertise_time * 1000);         // advertise_time秒アドバタイズする
  pAdvertising_->stop();                // アドバタイズ停止
}

void BLEBroadcaster::deepsleep(const int deepsleep_time)
{
  esp_deep_sleep(1000000LL * deepsleep_time);         // deepsleep_time秒Deep Sleepする
}
