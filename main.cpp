/**
 ** i2c LCD test application
 **
 ** Author: Kaj-Michael Lang <milang@tal.org>
 ** Copyright 2014 - Under creative commons license 3.0 Attribution-ShareAlike CC BY-SA
 **/

/**

	zapis do LCD za posrednictwem pliku
**/
#include <sys/ioctl.h>
#include "LiquidCrystal_I2C.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (int argc, char *argv []) {
// i2c address
uint8_t i2c=0x27;
// Control line PINs
uint8_t en=2;
uint8_t rw=1;
uint8_t rs=0;

// Data line PINs
uint8_t d4=4;
uint8_t d5=5;
uint8_t d6=6;
uint8_t d7=7;

// Backlight PIN
uint8_t bl=3;

// LCD display size
uint8_t rows=4;
uint8_t cols=20;

uint8_t linia=0; 

if(argc == 1)
{
 cout << "wywolanie:\n\t lcdwrite \"linia 1\" \"linia 2\"\n\n";
 return 0;
}

LiquidCrystal_I2C lcd("/dev/i2c-0", i2c, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

lcd.begin(cols, rows);

lcd.on();
lcd.clear();

for(uint8_t i = 1; i<=argc-1; i++)
{
	lcd.setCursor(0, i-1);
	lcd.print(argv[i]);
}
return 0;

}
