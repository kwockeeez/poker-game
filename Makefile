CC        = clang
CFLAGS    = -g -Wall -Werror
VFLAGS    = -s --leak-check=full --tool=memcheck

PREF_SRC  = ./src/
PREF_DIST = ./dist/

TARGET    = $(PREF_DIST)main.bin
SRC       = $(wildcard $(PREF_SRC)*.c)
DIST      = $(patsubst $(PREF_SRC)%.c, $(PREF_DIST)%.o, $(SRC))

default: $(TARGET)

.PHONY: valgrind check clear

$(TARGET): $(DIST)
	$(CC) $(CFLAGS) $(DIST) -o $(TARGET)

$(PREF_DIST)%.o: $(PREF_SRC)%.c
	$(CC) $(CFLAGS) -c $< -o $@

valgrind:
	valgrind $(VFLAGS) $(TARGET)

check:
	clang-format -i $(PREF_SRC)*.*

clear:
	rm -f $(TARGET) $(PREF_DIST)*.o