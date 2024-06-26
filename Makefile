#g++ dispatcher.cpp mem.cpp get_size.cpp msg_Buffer.cpp DrakIO_Server.cpp serial.cpp -l paho-mqttpp3 -l paho-mqtt3as -o DrakIO_Server 


CC = g++
CFLAGS = -Wall
LIBS = 

SRCS = mkH.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = mkH


# Default target
all:
	$(CC) $(SRCS) $(LIBS) -o $(TARGET)

new:
# Rule to compile object files
%.o: %.cpp
	$(CC) $(CFLAGS) $(LIBS) -c $< -o $@

# Rule to build the executable
#$(TARGET): $(OBJS)
#	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

 
# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
