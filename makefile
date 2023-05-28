CC=g++
CFLAGS= -Wall
LDFLAGS=
INSTALL_PATH=/usr/games/
EXEC=ricochet_robots

all: $(EXEC)

install: $(EXEC)
	cp $(EXEC) $(INSTALL_PATH)

uninstall:
	rm  $(INSTALL_PATH)$(EXEC)

$(EXEC): main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o
	rm $(EXEC)