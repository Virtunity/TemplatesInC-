#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <string.h>
#define CDynamicArray_defualt "CDA_DEFAULT"
#define mcompare(type, type1) (strcmp(#type, #type1) ==0)
// Initialize a Dynamic Array
#define CDynamicArray(T, name, ...) \
    struct { \
        T *arr; \
        unsigned int size; \
        unsigned int indexSize; \
        unsigned int capacity; \
    } name = { \
        .arr = NULL, \
        .size = sizeof((T[]){__VA_ARGS__}) / sizeof(T), \
        .indexSize = sizeof(T),\
        .capacity = (sizeof((T[]){__VA_ARGS__}) / sizeof(T)) * 2 \
    }; \
    do { \
        T temp_arr[] = {__VA_ARGS__}; \
        name.arr = (T *)malloc(name.capacity * sizeof(T)); \
        if (name.arr == NULL) { \
            fprintf(stderr, "Memory allocation failed for dynamic array.\n"); \
            exit(EXIT_FAILURE); \
        } \
        if (mcompare(T,const char*) && name.size == 1 && strcmp((const char*)temp_arr[0], CDynamicArray_defualt) == 0) { \
            name.size = 0; \
        } else { \
            memcpy(name.arr, temp_arr, name.size * sizeof(T)); \
        } \
    } while (0)

// Macro to set a value at a specified index
#define CDynamicArray_Set(name, index, value) \
    do { \
        if ((index) < (name).size) { \
            (name).arr[(index)] = (value); \
        } else { \
            fprintf(stderr, "Index out of bounds.\n"); \
        } \
    } while (0)

// Macro to fill the array with a specified value
#define CDynamicArray_Fill(name, value) \
    do { \
        for (unsigned int i = 0; i < (name).size; i++) { \
            (name).arr[i] = (value); \
        } \
    } while (0)

// Macro to add a value to the array, resizing if necessary
#define CDynamicArray_Add(name, value) \
    do { \
        if ((name).size == (name).capacity) { \
            (name).capacity *= 2; \
            void* temp = (void*)realloc((name).arr, (name).capacity * name.indexSize); \
            if (temp == NULL) { \
                fprintf(stderr, "Memory reallocation failed for dynamic array.\n"); \
                exit(EXIT_FAILURE); \
            } \
            (name).arr = temp; \
        } \
        (name).arr[(name).size++] = (value); \
    } while (0)

// Macro to get a value at a specified index
#define CDynamicArray_At(name, index) \
    (assert((index) < (name).size), (name).arr[(index)])

#define CDynamicArray_Free(name)\
do{\
    free(name.arr);\
    name.arr = NULL;\
    name.size = 0;\
    name.capacity = 0;\
} while (0)
