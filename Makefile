CXX ?= g++

# path #
SRC_PATH = src
BUILD_PATH = _build
BIN_PATH = $(BUILD_PATH)/bin
INSTALL_LOC ?= /usr/bin
CURRENT_DIR = $(shell pwd)

# executable #
BIN_NAME = isfml.out

# extensions #
SRC_EXT = cpp

# code lists #
# Find all source files in the source directory, sorted by
# most recently modified
SOURCES = $(shell find $(SRC_PATH) -name '*.$(SRC_EXT)' | sort -k 1nr | cut -f2-)
# Set the object file names, with the source directory stripped
# from the path, and the build path prepended in its place
OBJECTS = $(SOURCES:$(SRC_PATH)/%.$(SRC_EXT)=$(BUILD_PATH)/%.o)
# Set the dependency files that will be used to add header dependencies
DEPS = $(OBJECTS:.o=.d)

# flags #
COMPILE_FLAGS = -std=c++11 -Wall -Wextra
INCLUDES = -I include/ -I /usr/local/include -I include/imgui -I include/imgui-SFML -I include/SFML-2.4.2
LIBS_PATH = -L lib/SFML-2.4.2
# Space-separated pkg-config libraries used by this project
LIBS =-lsfml-graphics -lsfml-window -lsfml-system -lGL -lGLU -lgcc -lpthread

.PHONY: default_target
default_target: release

.PHONY: release
release: export CXXFLAGS := $(CXXFLAGS) $(COMPILE_FLAGS)
release: dirs
	@$(MAKE) all

.PHONY: dirs
dirs:
	@echo "Creating directories"
	@mkdir -p $(dir $(OBJECTS))
	@mkdir -p $(BIN_PATH)

.PHONY: clean
clean:
	@echo "Deleting $(BIN_NAME) symlink"
	@$(RM) $(BIN_NAME)
	@echo "Deleting directories"
	@$(RM) -r $(BUILD_PATH)
	@$(RM) -r $(BIN_PATH)

# checks the executable and symlinks to the output
.PHONY: all
all: $(BIN_PATH)/$(BIN_NAME)
	@echo "Making symlink: $(BIN_NAME) -> $<"
	@$(RM) $(BIN_NAME)
	@ln -s $(BIN_PATH)/$(BIN_NAME) $(BIN_NAME)

# Creation of the executable
$(BIN_PATH)/$(BIN_NAME): $(OBJECTS)
	@echo "	LD $@"
	@$(CXX) $(OBJECTS) $(LIBS_PATH) -o $@ $(LIBS)

# Add dependency files, if they exist
-include $(DEPS)

# Source file rules
# After the first compilation they will be joined with the rules from the
# dependency files to provide header dependencies
$(BUILD_PATH)/%.o: $(SRC_PATH)/%.$(SRC_EXT)
	@echo "	CC $<"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -MP -MMD -c $< -o $@
