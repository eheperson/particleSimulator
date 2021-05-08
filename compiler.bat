cls

cmake -G "MinGW Makefiles" -S . -B ./build

cmake --build build
cd build

mingw32-make

cd ..