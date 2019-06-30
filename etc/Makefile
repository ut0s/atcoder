TARGET = a

CXX = g++
CXXFLAGS = -Wall -O2 -std=c++14
SRCS = a.cpp
OBJS := $(SRCS:.cpp=.o) #SRCSの各ファイルのサフィックスの.cppを.oに変換

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS)

clean:
	rm -f $(TARGET) $(OBJS) a b c d e f
