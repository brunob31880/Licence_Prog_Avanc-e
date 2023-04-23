# !/usr/bin

mkdir ./build
pushd build
cmake -G "Unix Makefiles"  -DCMAKE_BUILD_TYPE=Debug ../
popd