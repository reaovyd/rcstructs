CC=gcc
SRC=src
BUILD=build
TARGET=bin/rcstructs_driver
TARGET_TEST=bin/rcstructs_debug_driver

EXT=c
SOURCES=$(shell find $(SRC) -type f -name *.$(EXT))
TEST_SOURCES=$(filter-out src/rcstructs.c, test/rcstructs_debug_driver.c $(wildcard $(SRC)/*.$(EXT)))
OBJECTS=$(patsubst $(SRC)/%,$(BUILD)/%,$(SOURCES:.$(EXT)=.o))
CFLAGS=-Wall -Werror -Wextra -fsanitize=address -std=c18
DEBUG_FLAGS= -Wall -Werror -Wextra -fsanitize=address -fsanitize=undefined -fstack-protector -std=c18  
LIBS=-lm 
INC=-I include

$(TARGET) : $(OBJECTS)
	$(CC) $^ -o $(TARGET) $(CFLAGS) $(LIBS)

$(BUILD)/%.o: $(SRC)/%.$(EXT)
	@mkdir -p $(BUILD)
	$(CC) $(LIBS) $(CFLAGS) $(INC) -c -o $@ $<
tester:
	$(CC) $(DEBUG_FLAGS) $(LIBS) $(INC) $(TEST_SOURCES) -o $(TARGET_TEST) 

clean:
	@echo " Cleaning..."
	@echo " $(RM) -r $(BUILD) $(TARGET)"; $(RM) -r $(BUILD) $(TARGET)

.PHONY: clean
