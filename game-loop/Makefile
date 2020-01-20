
#
include ../makedefs

PGM = game_loop

OBJS = \
	main.o \
	Game.o

LDFLAGS += -lSDL2

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(CFLAGS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
