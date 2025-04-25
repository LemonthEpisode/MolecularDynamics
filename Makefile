# compiler
CXX := g++
CXXFLAGS := -std=c++17 -Isrc -IC:\Users\alisa\code\SDL2\x86_64-w64-mingw32\include\SDL2
LDFLAGS := -L C:\Users\alisa\code\SDL2\x86_64-w64-mingw32\lib -lmingw32 -lSDL2main -lSDL2

# Files
SRC := src/Display3D.cpp src/Particle.cpp
OBJ := $(SRC:.cpp=.o)
TARGET := program.exe

TEST_SRC := tests/Display3D_test.cpp src/Display3D.cpp
TEST_OBJ := $(TEST_SRC:.cpp=.o)
TEST_TARGET := display_test.exe

# default target
all: $(TARGET)

# link object into executable
$(TARGET) : $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

# compile source into object
%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

run: $(TARGET)
	./$(TARGET)

# --- TESTING ---
display3D_test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(TEST_OBJ) -o $@ $(LDFLAGS)

run_display3D_test: display3D_test
	./$(TEST_TARGET)

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TARGET) $(TEST_TARGET)

# g++ -c Display3D.cpp Display3D.test.cpp -I C:\Users\alisa\code\SDL2\x86_64-w64-mingw32\include\SDL2 
# g++ Display3D.o Display3D.test.o -o disp -L C:\Users\alisa\code\SDL2\x86_64-w64-mingw32\lib -lmingw32 -lSDL2main -lSDL2
# ./disp