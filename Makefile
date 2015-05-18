CXX := g++
CPPFLAGS := -std=c++11
CXXFLAGS := -O2 -march=native

SRC := NearestNeighborResizeOptimized.cpp

OBJ := $(patsubst %.cpp,%.o, $(SRC))

BIN := optimized

all: $(BIN)

$(BIN) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $@ -o $<

.PHONY: all clean

clean:
	git clean -if
