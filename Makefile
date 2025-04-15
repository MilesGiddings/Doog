# Add this line before the build rule
$(shell mkdir -p build)

# Existing code
CXX = clang++
CXXFLAGS = -std=c++11 -Iinclude -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

SRC = $(wildcard src/*.cpp)
TARGET = build/Doog

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)