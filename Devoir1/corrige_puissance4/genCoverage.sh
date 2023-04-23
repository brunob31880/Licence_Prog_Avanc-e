# !/usr/bin

gcov build/CMakeFiles/Puissance4.dir/src/*
lcov -c -o coverage.info -d .
genhtml -o report coverage.info
