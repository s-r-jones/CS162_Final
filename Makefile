CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = test
MAKEFLAGS = -k

all: $(PROGS)

test:
	$(CC) $(CFLAGS) main.cpp Dice.cpp Character.cpp BlueMen.cpp ReptilePeople.cpp CoreRoom.cpp BattleRoom.cpp Room.cpp Bridge.cpp Player.cpp StandardRoom.cpp world.cpp -o test
clean:
	rm -f *.o test