g++ -std=c++11 -static %1 -I ..\..\..\tmcommon\include -I ..\..\..\tmfhlib\include -I ..\..\dl\include -I..\include  -linventorybl -L ..\lib -linventorydl -L..\..\dl\lib -l tmcommon -L ..\..\..\tmcommon\lib -l tmfh -L ..\..\..\tmfhlib\lib -o %2