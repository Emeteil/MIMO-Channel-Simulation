mkdir -p Build;
cd Build;

cmake ..;
cmake --build .;
./a.out;