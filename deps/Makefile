
LUA_A=  liblua.a
CORE_O= lapi.o lcode.o lctype.o ldebug.o ldo.o ldump.o lfunc.o lgc.o llex.o \
        lmem.o lobject.o lopcodes.o lparser.o lstate.o lstring.o ltable.o \
        ltm.o lundump.o lvm.o lzio.o
LIB_O=  lauxlib.o lbaselib.o lbitlib.o lcorolib.o ldblib.o liolib.o \
        lmathlib.o loslib.o lstrlib.o ltablib.o lutf8lib.o loadlib.o linit.o

BASE_O= $(CORE_O) $(LIB_O)

LUA_T=  lua
LUA_O=  lua.o

LUAC_T= luac
LUAC_O= luac.o

ALL_O= $(BASE_O) $(LUA_O) $(LUAC_O)
ALL_T= $(LUA_A) $(LUA_T) $(LUAC_T)
ALL_A= $(LUA_A)

# Targets start here.
default: $(PLAT)

all:    $(ALL_T)

o:      $(ALL_O)

a:      $(ALL_A)

$(LUA_A): $(BASE_O)
        $(AR) $@ $(BASE_O)
        $(RANLIB) $@

$(LUA_T): $(LUA_O) $(LUA_A)
        $(CC) -o $@ $(LDFLAGS) $(LUA_O) $(LUA_A) $(LIBS)

$(LUAC_T): $(LUAC_O) $(LUA_A)
        $(CC) -o $@ $(LDFLAGS) $(LUAC_O) $(LUA_A) $(LIBS)

clean:
        $(RM) $(ALL_T) $(ALL_O)

