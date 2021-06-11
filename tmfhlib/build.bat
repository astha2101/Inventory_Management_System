@echo off
rd /q/s lib
md lib
rd /q/s temp
md temp
g++ -std=c++11 -I include -I..\tmcommon\include -c src\filehandler.cpp src\serializedstream.cpp 
move *.o temp >fhaltu
del fhaltu 
ar rcs lib\tmfh.lib temp\filehandler.o temp\serializedstream.o