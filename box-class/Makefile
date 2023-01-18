CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main-box.cc box.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=main-box

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
