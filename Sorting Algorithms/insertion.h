#pragma once

#ifndef INSERTION_SORT
#define INSERTION_SORT

template<typename type, typename type2>
class Insertion
{
public:
	bool sort(type dataArray[], int lenDataArray, type2 order);
};

template<typename type, typename type2>
inline bool Insertion<type, type2>::sort(type dataArray[], int lenDataArray, type2 order)
{
	if (order == 'a' || order == 'A' || order == 1)
	{
		try
		{
			for (int n = 1; n < lenDataArray; n++)
			{
				int index = n - 1;
				type key = dataArray[n];
				while (index >= 0 && dataArray[index] > key)
				{
					dataArray[index + 1] = dataArray[index];
					index--;
				}
				dataArray[index + 1] = key;
			}
			return true;
		}
		catch (const std::exception&)
		{
			return false;
		}
	}
	else if (order == 'd' || order == 'D' || order == 0)
	{
		try
		{
			for (int n = 1; n < lenDataArray; n++)
			{
				int index = n - 1;
				type key = dataArray[n];
				while (index >= 0 && dataArray[index] < key)
				{
					dataArray[index + 1] = dataArray[index];
					index--;
				}
				dataArray[index + 1] = key;
			}
			return true;
		}
		catch (const std::exception&)
		{
			return false;
		}
	}
	else {
		cout << "error:\n" << "Expected (a, A, d, D, 0, 1), recieved: " << order;
		return false;
	}
}

#endif // !INSERTION_SORT