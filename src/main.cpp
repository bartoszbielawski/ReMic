#include <Arduino.h>
#include <I2S.h>

static const size_t i2s_buffer_size = 256;
static const size_t i2s_channels = 2;

int16_t i2s_data[i2s_buffer_size * i2s_channels];
/*
    PIN_I2S_SCK 14    //clock 
    PIN_I2S_FS 25     //frame sync
    PIN_I2S_SD 26    //serial data
    PIN_I2S_SD_OUT 26
    PIN_I2S_SD_IN 35
*/



void i2s_read_callback()
{
  auto a = I2S.available();   //in bytes

  I2S.read(i2s_data, a);       //in bytes

  //process buffer  
}

void setup() {
  //16kHz, 16b/s
  I2S.begin(I2S_PHILIPS_MODE,  16000, 16);
  I2S.setBufferSize(i2s_buffer_size);
  I2S.setAllPins();

}

void loop() {
  
}