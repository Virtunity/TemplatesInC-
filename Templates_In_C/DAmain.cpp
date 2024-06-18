#include "DynamicArray/Array.hpp"
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

	DynamicArray< const char*> Subscribe = { "I Love", "Assembly" };
	Subscribe.add("bro"); 
	Subscribe.add("bro1"); 
	Subscribe.add("bro2"); 
	Subscribe.add("bro3"); 
	Subscribe.add("bro4"); 
	Subscribe.add("bro5");
	Subscribe.add("bro6");
	fprintArray(Subscribe, "%s");

	while (true)
	{

	}
}