#pragma once

#ifndef QUICK_SORT
#define QUICK_SORT

template<typename type, typename type2>
class Quick
{
protected:
	type2 sortOrder;

	int arrayPartition(type dataArray[], int low, int high);
	void quick_sort(type dataArray[], int low, int high);
public:
	bool sort(type dataArray[], int dataArrayLen, type2 order);
};

template<typename type, typename type2>
inline int Quick<type, type2>::arrayPartition(type dataArray[], int low, int high)
{
	if (sortOrder == 'a' || sortOrder == 'A' || sortOrder == 1)
	{
		try
		{
			type pivot = dataArray[high];

			int index = (low - 1);

			for (int n = low; n <= high - 1; n++)
			{
				if (dataArray[n] < pivot)
				{
					index++;
					std::swap(dataArray[index], dataArray[n]);
				}
			}
			std::swap(dataArray[index + 1], dataArray[high]);
			return (index + 1);
		}
		catch (const std::exception&)
		{
			std::cout << "ERROR\n";
		}
	}
	else if (sortOrder == 'd' || sortOrder == 'D' || sortOrder == 0)
	{
		try
		{
			type pivot = dataArray[high];

			int index = (low - 1);

			for (int n = low; n <= high - 1; n++)
			{
				if (dataArray[n] > pivot)
				{
					index++;
					std::swap(dataArray[index], dataArray[n]);
				}
			}
			std::swap(dataArray[index + 1], dataArray[high]);
			return (index + 1);
			return true;
		}
		catch (const std::exception&)
		{
			std::cout << "ERROR\n";
		}
	}
	else {
		cout << "error:\n" << "Expected (a, A, d, D, 0, 1), recieved: " << sortOrder;
	}
}

template<typename type, typename type2>
inline void Quick<type, type2>::quick_sort(type dataArray[], int low, int high)
{
	try
	{
		if (low < high)
		{
			int partitionIndex = arrayPartition(dataArray, low, high);

			quick_sort(dataArray, low, partitionIndex - 1);
			quick_sort(dataArray, partitionIndex + 1, high);
		}
	}
	catch (const std::exception&)
	{
		std::cout << "ERROR\n";
	}
}

template<typename type, typename type2>
inline bool Quick<type, type2>::sort(type dataArray[], int dataArrayLen, type2 order)
{
	try
	{
		int low = 0;
		int high = dataArrayLen - 1;
		this->sortOrder = order;
		quick_sort(dataArray, low, high);
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}
#endif // !QUICK_SORT