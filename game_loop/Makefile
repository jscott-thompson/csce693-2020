
#
include ../makedefs

PGM = game_loop

OBJS = \
	main.o \
	Game.o

LDFLAGS += -Bdynamic -lSDL2

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
