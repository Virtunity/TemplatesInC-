#include <iostream>
#include <cassert>
#include <cstdarg>
template <class T>
struct DynamicArray {
    T* arr;
    unsigned int Capacity;
    unsigned int size = 0;

    // Constructor with variadic arguments
    template <typename... Args>
    DynamicArray(Args... args)
    {
        T temp_arr[] = { args... }; // Convert args to Array
        size = sizeof...(args); // get arg count
        Capacity = size * 2;
        arr = new T[Capacity]; //init arr
        for (unsigned int i = 0; i < Capacity; i++)
        {
            arr[i] = temp_arr[i]; 
        }
    }

    // Set element at index
    void set(unsigned int index, T val) {
        if (index < size) {
            arr[index] = val;
        }
        else {
            std::cerr << "Index out of bounds." << std::endl;
        }
    }

    // Add element to array
    void add(T val) {
        if (size == Capacity) {
            // Resize the array (increase by a factor)
            Capacity *= 2;
            T* temp = new T[Capacity];
            if (temp == NULL) {
                    fprintf(stderr, "Memory reallocation failed for dynamic array.\n");
                    exit(EXIT_FAILURE);
            }
            // Copy existing elements
            for (unsigned int i = 0; i < size; ++i) {
                temp[i] = arr[i];
            }

            // Deallocate old memory
            delete[] arr;
            arr = temp;
        }

        arr[size++] = val;
    }

    // Fill array with a value
    void fill(T val) { 
        for (unsigned int i = 0; i < size; i++) {
            arr[i] = val; 
        }
    }

    // Access element at index
    T at(unsigned int index) {
        if (index < size) {
            return arr[index];
        }
        else {
            std::cerr << "Index out of bounds." << std::endl;
            return T(); // Return a default-constructed T 
        }
    }

    // Destructor
    ~DynamicArray() {
        delete[] arr;
    }
};
