CC=g++
STD=c++17
CFLAGS=-Wall -Wextra -std=$(STD)
TARGET_NAME=tp2
TARGET_PATH=$(BUILD_PATH)/$(TARGET_NAME)
BUILD_PATH=./build
SOURCE_PATH=./src
LIB_PATH=./include

SOURCE_EXT := cpp
SOURCES := $(shell find $(SOURCE_PATH) -path '*.$(SOURCE_EXT)')
OBJECTS := $(patsubst $(SOURCE_PATH)/%,$(BUILD_PATH)/%,$(SOURCES:.$(SOURCE_EXT)=.o))

all: $(TARGET_NAME)

$(BUILD_PATH)/%.o: $(SOURCE_PATH)/%.$(SOURCE_EXT) $(LIB_PATH)/%.hpp
	mkdir -p $(@D)
	$(CC) -c $(CFLAGS) -o $@ $<

$(TARGET_NAME): $(OBJECTS) ./main.$(SOURCE_EXT)
	$(CC) $(CFLAGS) -o $(TARGET_PATH) ./main.$(SOURCE_EXT) $(OBJECTS)

clean:
	rm -rf $(BUILD_PATH)/*

run:
	$(TARGET_PATH) -c ./input/seed -b > ./output/crawler.log
	
mem:
	valgrind --leak-check=full --show-leak-kinds=all --log-file="./output/mem.log" --max-threads=100 $(TARGET_PATH) -c ./input/seed -b > ./output/crawler.log