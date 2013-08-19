SOURCE_DIR = source
OUTPUT_DIR = output

SOURCE_FILES = $(wildcard $(SOURCE_DIR)/*.cpp)
EXECUTABLE_FILES = $(patsubst $(SOURCE_DIR)/%.cpp,$(OUTPUT_DIR)/%,$(SOURCE_FILES))


all: $(EXECUTABLE_FILES)

$(OUTPUT_DIR)/%: $(SOURCE_DIR)/%.cpp Makefile $(OUTPUT_DIR)/.dir
	$(CXX) -Wall -std=c++0x -o $@ $<

$(OUTPUT_DIR)/.dir:
	if [ ! -e $(OUTPUT_DIR) ]; then mkdir $(OUTPUT_DIR); touch $(OUTPUT_DIR)/.dir; fi

clean:
	rm -rfv $(OUTPUT_DIR)

