#include <stdio.h>
#include "StaticArray/Array.h" 
#define fprintArray(ArrayStruct, type)\
{\
	printf("Array " # ArrayStruct  " Elements are:\n");\
	for (size_t i = 0; i < ArrayStruct.size; i++)\
	{\
		printf(type "\n",ArrayStruct.arr[i]);\
	}\
}
typedef const char* cstring;
int main()
{
	printf("Running C Code\n\n");

	printf("Int's Truns\n\n"); 

	CStaticArray(int, 4, V, 1,2,3,4);

	fprintArray(V, "%d"); 
	CStaticArray_set(V, 1, 6); 
	fprintArray(V, "%d");
	printf("Array V at index 3 is %d\n", CStaticArray_at(V, 3));

	CStaticArray_fill(V, 100);
	fprintArray(V, "%d");

	printf("\n\nString's Turn\n\n");
	
	CStaticArray(cstring, 2, s, "C", "C++");
	CStaticArray_set(s, 0, "DLang"); 
	fprintArray(s, "%s");

	while (1){}
	return 0;
}