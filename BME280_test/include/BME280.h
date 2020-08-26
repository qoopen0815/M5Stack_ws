#ifndef BME280_H
#define BME280_H

#include <Wire.h>

//アドレス指定
#define BME280_ADDR 0x76
#define CONFIG      0xF5
#define CTRL_MEAS   0xF4
#define CTRL_HUM    0xF2

struct bme280_data
{
  float temperature;
  float humidity;
  float pressure;
};

class BME280
{
public:
  BME280(void);
  virtual ~BME280();

  void begin(void);
  void update(void);
  void getSensorData(bme280_data &data);
  float readTemperature(void);
  float readHumidity(void);
  float readPressure(void);

private:
  int32_t   BME280_compensate_T_int32(int32_t adc_T);
  uint32_t  bme280_compensate_H_int32(int32_t adc_H);
  uint32_t  BME280_compensate_P_int32(int32_t adc_P);

private:
  //気温補正データ
  uint16_t dig_T1;
  int16_t  dig_T2;
  int16_t  dig_T3;

  //湿度補正データ
  uint8_t  dig_H1;
  int16_t  dig_H2;
  uint8_t  dig_H3;
  int16_t  dig_H4;
  int16_t  dig_H5;
  int8_t   dig_H6;

  //気圧補正データ
  uint16_t dig_P1;
  int16_t  dig_P2;
  int16_t  dig_P3;
  int16_t  dig_P4;
  int16_t  dig_P5;
  int16_t  dig_P6;
  int16_t  dig_P7;
  int16_t  dig_P8;
  int16_t  dig_P9;

  unsigned char dac[26];
  unsigned int i;

  int32_t t_fine;
  int32_t adc_P, adc_T, adc_H;

  int32_t  temp_cal;
  uint32_t humi_cal, pres_cal;
  float temp, humi, pres;
};

#endif // BME280_H
