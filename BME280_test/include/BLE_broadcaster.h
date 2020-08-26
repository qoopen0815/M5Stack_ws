#ifndef BLE_BROADCASTER_H
#define BLE_BROADCASTER_H

#include "BLEDevice.h"
#include "BLEUtils.h"
#include "BLEServer.h"
#include "esp_sleep.h"

class BLEBroadcaster
{
public:
  BLEBroadcaster(const std::string name);
  virtual ~BLEBroadcaster();

  void setAdvData(const BLEAdvertising *pAdvertising);
  void advertise(const int advertise_time);
  void deepsleep(const int deepsleep_time);

private:
  BLEServer *pServer_;
  BLEAdvertising *pAdvertising_;

  RTC_DATA_ATTR static uint8_t seq_; // remember number of boots in RTC Memory
};

#endif //BLE_BROADCASTER_H
