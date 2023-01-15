#define ENABLE_GxEPD2_GFX 0

#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>

const uint8_t PIN_SPI_RST_RES_RESET = 2; // Used for SSD1680
const uint8_t PIN_SPI_DC_RS_A0 = 4; // Used for SSD1680
const uint8_t PIN_SPI_CS_SS = 5; // Used for SSD1680
const uint8_t PIN_SPI_SDA_SDI_DARA_IN_MOSI = 23; // Used for SSD1680
const uint8_t PIN_SPI_SDO_DATA_OUT_MISO = 12;
const uint8_t PIN_SPI_SCK_CLK_SCL_SCLK = 18; // Used for SSD1680
const uint8_t PIN_I2C_SDA = 21;
const uint8_t PIN_I2C_SCL = 22;
const uint8_t PIN_UART_TX = 17;
const uint8_t PIN_UART_RX = 16;
const uint8_t PIN_DISPLAY_BUSY = 15; // Used for SSD1680

// 122x250
GxEPD2_3C<GxEPD2_213_Z98c, GxEPD2_213_Z98c::HEIGHT> display(GxEPD2_213_Z98c(/*CS=5*/
        PIN_SPI_CS_SS,
        PIN_SPI_DC_RS_A0,
        PIN_SPI_RST_RES_RESET,
        PIN_DISPLAY_BUSY
));

const char Text1[] = "Test black text";
const char Text2[] = "Test red text";

void helloWorld() {
    display.setRotation(1);
    display.setFont(&FreeMonoBold9pt7b);
    display.setFullWindow();
    display.firstPage();
    do {
        display.fillScreen(GxEPD_WHITE);
        display.setTextColor(GxEPD_BLACK);
        display.setCursor(20, 40);
        display.print(Text1);
        display.setTextColor(GxEPD_RED);
        display.setCursor(20, 80);
        display.print(Text2);
    } while (display.nextPage());
}

void setup() {
    display.init(115200, true, 50, false);
    helloWorld();
    display.hibernate();
}


void loop() {

}