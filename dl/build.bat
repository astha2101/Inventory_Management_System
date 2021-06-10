@echo off
rd /q/s lib
md lib
rd /q/s tmp
md tmp
g++ -std=c++11 -I..\..\tmcommon\include -I..\..\tmfhlib\include -I include -c src\*.cpp
move *.o tmp >fhaltu
del fhaltu
ar rcs   lib\inventorydl.lib    tmp\*.o
