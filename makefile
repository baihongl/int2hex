TARGET = int2hex.a
OBJECT = main.o  
$(TARGET):$(OBJECT)
	gcc $(OBJECT) -o $(TARGET) -lm -l pthread
mycom.o:main.c global.h
	gcc -c main.c
clean:
	rm *.o $(TARGET)
