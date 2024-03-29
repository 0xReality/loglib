CC=gcc
CFLAGS=-Wall

TARGET=err

all: $(TARGET)

$(TARGET): main.o logs.o err.o
	$(CC) $(CFLAGS) main.o logs.o err.o -o $(TARGET)

main.o: main.c log_h/logs.h err_h/err.h
	$(CC) $(CFLAGS) -c main.c

logs.o: log_h/logs.c log_h/logs.h
	$(CC) $(CFLAGS) -c log_h/logs.c

err.o: err_h/err.c err_h/err.h
	$(CC) $(CFLAGS) -c err_h/err.c
	
clean:
	rm -f *.o $(TARGET)
cl:
	rm -f logs/* 
c: 
	rm -f *.o $(TARGET)
	rm -f logs/* 
