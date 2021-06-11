@echo off
rd /q/s tmp
md tmp
rd /q/s lib 
md lib
g++ -std=c++11 -I include -c src\*.cpp
move *.o tmp >fhaltu
del fhaltu
ar rcs lib\tmcommon.lib tmp\*.o