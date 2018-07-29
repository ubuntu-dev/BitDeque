PROJECT := BitDeque
SOURCES := $(notdir $(shell find . -follow -name '*.cpp'))
DBGSRCS := $(SOURCES)
#SRCDIRS := $(sort $(dir $(shell find . ../libdg -follow -name '*.cpp')))
SRCDIRS := $(sort $(dir $(shell find . -follow -name '*.cpp')))
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))
DBGOBJS := $(patsubst %.cpp,%.o,$(DBGSRCS))
INCLUDE += $(patsubst %,-I%,$(SRCDIRS))
VPATH   := $(SRCDIRS)

CC      := g++
BIN     := /usr/local/bin
LIB     := /usr/local/lib
CFLAGS  := $(INCLUDE) -Wall -ansi -pipe
LDFLAGS := -lm -lc -lpthread

all: CFLAGS += -O2 -fomit-frame-pointer
all: $(PROJECT)

$(PROJECT): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(PROJECT) $(OBJECTS) $(LDFLAGS)
	strip $(PROJECT)

debug: CFLAGS += -O0 -g
debug: $(DBGOBJS)
	$(CC) $(CFLAGS) -o $(PROJECT)_dbg $(DBGOBJS) $(LDFLAGS)

clean:
	rm -f core *.o *.a *.log $(PROJECT) $(PROJECT)_dbg
