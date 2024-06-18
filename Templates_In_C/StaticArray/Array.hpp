template <class T, unsigned int len> 
struct StaticArray
{
	T arr[len];  
	unsigned int Size = len;
	void set(unsigned int index, T val) 
	{
		this->arr[index] = val; 
	}
	T at(unsigned int index)
	{
		return this->arr[index];
	}
	void fill(T val)
	{
		for (unsigned int i = 0; i < len; i++)
		{
			this->arr[i] = val;
		}
	}
};