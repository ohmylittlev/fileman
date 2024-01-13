TARGET = fileman 

DEVICE ?= AMD64
DEVICE ?= RK3326
DEVICE ?= RK3399
DEVICE ?= RK3566
DEVICE ?= RK3566_X55
DEVICE ?= RK3588
DEVICE ?= S922X
DEVICE ?= PC

START_PATH ?= "/"
RES_PATH ?= "./res"

ifeq ($(DEVICE),PC)
	CC = $(CXX)
	SDL2_CONFIG = sdl2-config
	START_PATH = $(PWD)
endif

SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst %cpp,%o,$(SRC))
DOMAIN = fileman
POT = po/$(DOMAIN).pot
PO = po/zh/$(DOMAIN).po
MO = po/zh/$(DOMAIN).mo
MO_INSTALL_PATH = lang/zh/LC_MESSAGES
MO_INSTALL = $(MO_INSTALL_PATH)/$(DOMAIN).mo
COMPILER_FLAGS =  $(shell $(SDL2_CONFIG) --cflags) -Wall -pedantic -Wfatal-errors -DDEVICE_$(DEVICE) -DSTART_PATH=\"$(START_PATH)\" -DRES_PATH=\"$(RES_PATH)\"
LINKER_FLAGS = $(shell $(SDL2_CONFIG) --libs) -lSDL2_image -lSDL2_ttf

all: $(TARGET) $(MO)

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LINKER_FLAGS)

%.o:%.cpp
	$(CC) -c $< -o $@ $(COMPILER_FLAGS)

$(MO): $(PO)
	msgfmt --output-file=$@ $< && mkdir -p $(MO_INSTALL_PATH) && cp $@ $(MO_INSTALL)

$(PO): $(POT)
	msgmerge --update $@ $<

$(POT): $(SRC)
	xgettext -k_ -j -lC++ -c -o $(POT) $(SRC)

clean :
	rm -f $(OBJ) $(TARGET) $(MO) $(MO_INSTALL)
