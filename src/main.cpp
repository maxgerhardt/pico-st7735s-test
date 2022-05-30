#include <Arduino.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_GFX.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_SPIDevice.h>

#define TFT_RST p15       // must be "PinName" value, not plain pin number! p15 = GP15.
#define TFT_DC p14        // data/command, also called RS (register select)
#define TFT_MOSI SPI_MOSI // use board default SPI pins
#define TFT_MISO SPI_MISO
#define TFT_SCLK SPI_SCK
#define TFT_CS p16

mbed::SPI *tftSPI = nullptr;
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup()
{
    Serial.begin(115200);
    // while(!Serial); // uncomment this to wait for a USB serial connection
    Serial.print(F("Hello! ST77xx TFT Test"));
    tftSPI = new mbed::SPI(TFT_MOSI, TFT_MISO, TFT_SCLK);
    tft.SetSPI(tftSPI);
    tft.initS(); // initialize ST7735S chip
    Serial.println(F("Initialized"));
}

void loop()
{
    tft.setTextSize(1);
    tft.setTextWrap(true);

    tft.setRotation(0);
    tft.fillScreen(ST7735_BLACK);
    tft.setRotation(0);
    tft.setTextColor(ST7735_WHITE);
    tft.setCursor(0 + 20, 0 + 20);
    tft.print("test");
    delay(1000);
}