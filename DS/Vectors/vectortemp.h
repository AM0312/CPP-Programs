template <typename T>

class vect
{
	T *arr;
	int cs, ms;

public:
	vect(int maxsize = 1)
	{
		cs = 0;
		ms = maxsize;
		arr = new T[ms];
	}

	void push(T d)
	{
		if (cs == ms)
		{
			T *oldArr = arr;
			ms *= 2;
			arr = new T[ms];

			for (int i = 0; i < cs; i++)
			{
				arr[i] = oldArr[i];
			}

			delete[] oldArr;
		}
		arr[cs] = d;
		cs++;
	}
	
	void pop()
	{
		if (cs >= 0)
		{
			cs--;
		}
	}

	bool isEmpty()
	{
		return cs == 0;
	}

	T front()
	{
		return arr[0];
	}

	T back()
	{
		return arr[cs - 1];
	}

	T at(int i)
	{
		return arr[i];
	}

	int size()
	{
		return cs;
	}

	int capacity()
	{
		return ms;
	}

	T operator[](int i)
	{
		return arr[i];
	}
};
