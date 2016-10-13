C++ i2c LCD library
===================

Wyswietlanie komunikatow za pomoca I2C na lcd 

Wiecej na http://www.orangepi.pl

### Instalacja

	git clone https://github.com/labapawel/liquidcrystal-i2c.git

### kompilacja

	make

### Wykonanie 

	lcdwrite "Linia jeden" "linia dwa"

### Autor biblioteki

C++ i2c LCD display library for Linux devices using the i2c device nodes.

Based on the "New LiquidCrystal" library from https://bitbucket.org/fmalpartida/new-liquidcrystal/

Only the i2c functionality is kept from the arduino original library, there is no support for
other methods of accessing the LCD screens.

License as the original (CC-BY-SA), changes and Linux i2c device adaptions are (C) Kaj-Michael Lang <milang@tal.org>

