CC = g++
CFLAGS = -c -Wall -Iinclude
LDFLAGS =
SRC = src/
SOURCES = $(SRC)tag.cpp $(SRC)parser.cpp
OBJECTS = $(subst src/,out/,$(SOURCES:.cpp=.o))
EXECUTABLE = hrml
OUTDIR = out/

all: setup build

setup:
	mkdir -p $(OUTDIR)

build: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $(subst src/,out/,$@)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)