/***************************************************
  This is a library for the Adafruit 1.8" SPI display.
  This library works with the Adafruit 1.8" TFT Breakout w/SD card
  ----> http://www.adafruit.com/products/358
  as well as Adafruit raw 1.8" TFT display
  ----> http://www.adafruit.com/products/618
 
  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/

#ifndef _ADAFRUIT_ST7735H_
#define _ADAFRUIT_ST7735H_

#include "mbed.h"
#include <Arduino.h>
#include <SPI.h>
#include "Adafruit_GFX.h"

#define boolean bool

// some flags for initR() :(
#define INITR_GREENTAB 0x0
#define INITR_REDTAB   0x1
#define INITR_BLACKTAB   0x2

#define ST7735_TFTWIDTH  128
#define ST7735_TFTHEIGHT 160

#define ST7735_NOP     0x00
#define ST7735_SWRESET 0x01
#define ST7735_RDDID   0x04
#define ST7735_RDDST   0x09

#define ST7735_SLPIN   0x10
#define ST7735_SLPOUT  0x11
#define ST7735_PTLON   0x12
#define ST7735_NORON   0x13

#define ST7735_INVOFF  0x20
#define ST7735_INVON   0x21
#define ST7735_DISPOFF 0x28
#define ST7735_DISPON  0x29
#define ST7735_CASET   0x2A
#define ST7735_RASET   0x2B
#define ST7735_RAMWR   0x2C
#define ST7735_RAMRD   0x2E

#define ST7735_PTLAR   0x30
#define ST7735_COLMOD  0x3A
#define ST7735_MADCTL  0x36

#define ST7735_FRMCTR1 0xB1
#define ST7735_FRMCTR2 0xB2
#define ST7735_FRMCTR3 0xB3
#define ST7735_INVCTR  0xB4
#define ST7735_DISSET5 0xB6

#define ST7735_PWCTR1  0xC0
#define ST7735_PWCTR2  0xC1
#define ST7735_PWCTR3  0xC2
#define ST7735_PWCTR4  0xC3
#define ST7735_PWCTR5  0xC4
#define ST7735_VMCTR1  0xC5

#define ST7735_RDID1   0xDA
#define ST7735_RDID2   0xDB
#define ST7735_RDID3   0xDC
#define ST7735_RDID4   0xDD

#define ST7735_PWCTR6  0xFC

#define ST7735_GMCTRP1 0xE0
#define ST7735_GMCTRN1 0xE1

// Color definitions
#define ST7735_BLACK   0x0000
#define ST7735_BLUE    0x001F
#define ST7735_RED     0xF800
#define ST7735_GREEN   0x07E0
#define ST7735_CYAN    0x07FF
#define ST7735_MAGENTA 0xF81F
#define ST7735_YELLOW  0xFFE0  
#define ST7735_WHITE   0xFFFF


class Adafruit_ST7735 : public Adafruit_GFX {

 public:

  Adafruit_ST7735(PinName CS, PinName RS, PinName RST);

  void SetSPI(mbed::SPI* spi);
  void     initB(void);                             // for ST7735B displays
  void     initS(void);                             // for ST7735S displays
  void     initR(uint8_t options = INITR_GREENTAB); // for ST7735R
  void     setAddrWindow(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
  void     pushColor(uint16_t color);
  virtual void     fillScreen(uint16_t color);
  virtual void     drawPixel(int16_t x, int16_t y, uint16_t color);
  virtual void     drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
  virtual void     drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
  virtual void     fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
  void     setRotation(uint8_t r);
  void     invertDisplay(bool i);
  uint16_t Color565(uint8_t r, uint8_t g, uint8_t b);
  int DrawBitmapFile(const char *Name_BMP);
  int DrawBitmapFile(unsigned int x, unsigned int y, const char *Name_BMP);
  
 private:

  void     spiwrite(uint8_t),
           writecommand(uint8_t c),
           writedata(uint8_t d),
           commandList(uint8_t *addr),
           commonInit(uint8_t *cmdList);
           

  uint8_t  colstart, rowstart; // some displays need this changed

    mbed::SPI* lcdPort;            // does SPI MOSI, MISO and SCK
    mbed::DigitalOut _cs;         // does SPI CE
    mbed::DigitalOut _rs;         // register/date select
    mbed::DigitalOut _rst;        // does 3310 LCD_RST
};

#endif
