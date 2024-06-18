#include <stdio.h>
#include "DynamicArray/Array.h"
#define fprintArray(ArrayStruct, type)\
{\
	printf("Array " # ArrayStruct  " Elements are:\n");\
	for (size_t i = 0; i < ArrayStruct.size; i++)\
	{\
		printf(type "\n",ArrayStruct.arr[i]);\
	}\
}
struct d {
	
		const char** arr;
		unsigned int size; 
		unsigned int indexSize; 
		unsigned int capacity; 
};

void h(struct d * d) 
{
	printf("%s",d->arr[0]);
}

int main() 
{
	
	CDynamicArray(const char*, Subscribe, "I Love", "Assembly");    
	CDynamicArray_Add(Subscribe, "bro");  
	CDynamicArray_Add(Subscribe, "bro1");  
	CDynamicArray_Add(Subscribe, "bro2"); 
	CDynamicArray_Add(Subscribe, "bro3"); 
	CDynamicArray_Add(Subscribe, "bro4"); 
	CDynamicArray_Add(Subscribe, "bro5"); 
	CDynamicArray_Add(Subscribe, "bro6"); 

	fprintArray(Subscribe, "%s");
	h(&Subscribe);  

	while (1)
	{

	}
}