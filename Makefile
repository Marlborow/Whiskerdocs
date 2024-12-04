# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Directories
SRC_DIR = src
OBJ_DIR = src/obj

# Subdirectories
WEBSITEGENERATOR_DIR = $(SRC_DIR)/WebsiteGenerator

# Files
SRC = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(WEBSITEGENERATOR_DIR)/*.cpp)
HEADERS = $(wildcard $(SRC_DIR)/*.h) $(wildcard $(WEBSITEGENERATOR_DIR)/*.h)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(patsubst $(WEBSITEGENERATOR_DIR)/%.cpp, $(OBJ_DIR)/WebsiteGenerator/%.o, $(SRC)))

# Output binary
TARGET = whiskerdocs

# Default target
all: $(TARGET)

# Link the object files to create the final executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp files into obj/ directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/WebsiteGenerator/%.o: $(WEBSITEGENERATOR_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)/WebsiteGenerator
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Automatically track dependencies
-include $(OBJ:.o=.d)

# Generate dependency files for each .o file
$(OBJ_DIR)/%.d: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -MM -MT $(OBJ_DIR)/$*.o $< -MF $@

$(OBJ_DIR)/WebsiteGenerator/%.d: $(WEBSITEGENERATOR_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)/WebsiteGenerator
	$(CXX) $(CXXFLAGS) -MM -MT $(OBJ_DIR)/WebsiteGenerator/$*.o $< -MF $@

