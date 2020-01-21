# csce693-2020
Repo for student to clone and use for class homework

### deps folder contains Lua 5.3, sol 2 v3.0.3, and SDL2
Lua and SDL2 have been statically compiled with libraries placed into deps/lib folder

### Compiling SDL2:
configure --prefix=<install location> --enable-static

make

make install

### Compiling Lua:
make linux
