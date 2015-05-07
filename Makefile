CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		NearestNeigborResize.o

LIBS =

TARGET =	NearestNeigborResize.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
