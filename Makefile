HEADERS=I2CIO.h LCD.h LiquidCrystal_I2C.h
SRC=I2CIO.cpp LCD.cpp LiquidCrystal_I2C.cpp

OBJ=$(SRC:.cpp=.o)
STATIC=libliquidcrystali2c.a
LDFLAGS=

CC=g++

PREFIX=/usr/local

all: static lcdwrite

main.o: main.cpp

lcdwrite: main.o $(OBJ) 
	$(CC) -o lcdwrite main.o $(OBJ)

static:	$(STATIC)

$(OBJ): $(SRC) $(HEADERS)

$(STATIC): $(OBJ)
	ar rcs $(STATIC) $(OBJ)
	ranlib $(STATIC)

install: all
	install -d -m 755 $(PREFIX)/lib
	install -d -m 755 $(PREFIX)/include/liquidcrystal

	install -m 644 $(STATIC) $(PREFIX)/lib/
	install -m 644 $(HEADERS) $(PREFIX)/include/liquidcrystal

clean:
	rm -f *.o main
