# Variables
CC = cc
CFLAGS = -std=gnu90 -pedantic -Wall -O2
LDFLAGS =

# Sources
SOURCES = granthorner.c jbible.c
OBJECTS = $(SOURCES:.c=.o)

# Executable
EXECUTABLE = jbible

# pkg-config
# CFLAGS += `pkg-config --cflags sword`
# LDFLAGS += `pkg-config --libs sword`

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE)
