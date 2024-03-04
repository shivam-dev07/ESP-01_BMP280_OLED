
#include <Adafruit_GFX.h> //Libraries for the OLED and BMP280
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP280.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Declaring the display name (display)
Adafruit_BMP280 bmp;

void setup() {
Wire.pins(0, 2);
bmp.begin(); //Start the bmp
display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Start the OLED display
display.clearDisplay();
display.display();
display.setTextColor(WHITE);
display.setTextSize(1);
display.print("SHIVAM.V"); //Show the name, you can remove it or replace it
display.setCursor(32,12);
display.setTextSize(2);
display.println("BMP280");
display.display();
delay(2000);
}

void loop() {

display.clearDisplay();
float T = bmp.readTemperature()*9/5 + 32; //Read temperature in °C and conversion to °F
float P = bmp.readPressure()/3386.39; //Read Pressure in Pa and conversion to inches of mercury
float A = bmp.readAltitude(1019.66)*3.28084; //Calculating the Altitude, the "1019.66" is the pressure in(hPa) at sea level at day in your region
//If you don't know it just modify it until you get the altitude of your place

display.setCursor(0,0); //Oled display, just playing with text size and cursor to get the display you want
display.setTextColor(WHITE);
display.setTextSize(2);
display.print("Temp");

display.setCursor(0,18);
display.print(T,1);
display.setCursor(50,17);
display.setTextSize(1);
display.print("F");

display.setTextSize(1);
display.setCursor(65,0);
display.print("Pres");
display.setCursor(65,10);
display.print(P);
display.setCursor(100,10);
display.print("inHg");

display.setCursor(65,25);
display.print("Alt");
display.setCursor(90,25);
display.print(A,0);
display.setCursor(110,25);
display.print("ft");

display.display();
delay(2000);
}
