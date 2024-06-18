#include <stdio.h>
#include "Array.hpp"  
#define fprintArray(ArrayStruct, type)\
{\
	printf("Array " # ArrayStruct  " Elements are:\n");\
	for (size_t i = 0; i < ArrayStruct.Size; i++)\
	{\
		printf(type "\n",ArrayStruct.arr[i]);\
	}\
} 
typedef const char* cstring;
int main()
{
	printf("Running C++ Code\n\n"); 

	printf("Int's Truns\n\n"); 

	StaticArray<int, 4> V = { 1,2,3,4 }; 

	fprintArray(V, "%d"); 
	V.set(1, 6);
	fprintArray(V, "%d");
	printf("Array V at index 3 is %d\n", V.at(3));

	V.fill(100);
	fprintArray(V, "%d");

	printf("\n\nString's Turn\n\n"); 

	StaticArray<cstring, 2> s = { "C", "C++" }; 
	s.set(0, "DLang"); 
	fprintArray(s, "%s"); 

	while (true){}
	return 0;
}