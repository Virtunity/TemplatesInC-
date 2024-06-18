#define CStaticArray_at(ArrayStruct, index) ArrayStruct.arr[index]
#define CStaticArray_set(ArrayStruct, index, val) ArrayStruct.arr[index] = val
#define CStaticArray_fill(ArrayStruct, val) {\
	for (size_t i = 0; i < ArrayStruct.size; i++)\
	{\
		ArrayStruct.arr[i] = val;\
	}\
}
#define CStaticArray(T, len, name, ...) \
    struct { \
        T arr[len]; \
        unsigned int size; \
    } name = { {__VA_ARGS__}, len }