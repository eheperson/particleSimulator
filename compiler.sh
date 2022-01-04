clear

# cmake -G "MinGW Makefiles" -S . -B ./build
cmake -S . -B ./build


echo ""
echo " Configure End"
echo ""

# -----------------------------------
#       BUILD
# -----------------------------------
echo ""
echo " Build Begin"
echo ""

cd build
cmake --build .
# or 
# mingw32-make
cd ..

echo ""
echo " Build End"
echo ""

./build/simulatorEhe
