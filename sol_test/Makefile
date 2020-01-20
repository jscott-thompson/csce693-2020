
#
include ../makedefs

PGM = sol_test

OBJS = \
	main.o

CPPFLAGS += -I$(DEPS_INC_PATH)/lua5.3
LDFLAGS += -Bstatic -llua

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(CPPFLAGS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
