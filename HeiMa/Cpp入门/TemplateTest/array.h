#pragma once
template <class Element>
class Array
{
private:
	Element* data;

	int capacity;

	int size;

public:
	Array(int capacity)
		: capacity(capacity), size(0)
	{
		data = new Element[capacity];
	}

	Array(const Array<Element>& other)
		: capacity(other.capacity), size(other.size)
	{
		data = new Element[capacity];
		for (int i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
	}

	~Array()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}


	Array& operator=(const Array& other)
	{
		if (data = nullptr)
		{
			delete[] data;
			data = nullptr;
			capacity = 0;
			size = 0;
		}

		capacity = other.capacity;
		size = other.size;
		data = new Element[capacity];
		for (int i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}

		return *this;
	}

	void add(const Element& e)
	{
		if (capacity == size)
		{
			return;
		}

		data[size] = e;
		size++;
	}

	void removeLast()
	{
		if (size == 0)
		{
			return;
		}
		size--;
	}

	Element& operator[](int index)
	{
		return data[index];
	}


	int getSize() const
	{
		return size;
	}
};
