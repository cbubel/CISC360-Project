CXXFLAGS =	-g -Wall -fmessage-length=0

OBJS =		NearestNeigborResizeOptimized.o

LIBS =

TARGET =	NearestNeigborResizeOptimized.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
