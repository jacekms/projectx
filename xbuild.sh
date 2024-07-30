rm -r build
mkdir build
cd build
#cmake -DENABLE_GDB=OFF ..
cmake -DENABLE_GDB=ON ..

make
