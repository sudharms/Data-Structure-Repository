#pragma once

#ifndef SLECTION_SORT
#define SLECTION_SORT

template<typename type, typename type2>
class Selection
{
public:
	bool sort(type dataArray[], int lenDataArray, type2 order);
};

template<typename type, typename type2>
inline bool Selection<type, type2>::sort(type dataArray[], int lenDataArray, type2 order)
{
	if (order == 'a' || order == 'A' || order == 1) 
	{
		try
		{
			for (int i = 0; i <= (lenDataArray - 1); i++)
			{
				int lowestIndex = i;
				for (int n = i + 1; n < lenDataArray; n++)
				{
					if (dataArray[n] < dataArray[lowestIndex])
					{
						lowestIndex = n;
					}
				}
				std::swap(dataArray[i], dataArray[lowestIndex]);
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
			for (int i = 0; i <= (lenDataArray - 1); i++)
			{
				int highestIndex = i;
				for (int n = i + 1; n < lenDataArray; n++)
				{
					if (dataArray[n] > dataArray[highestIndex])
					{
						highestIndex = n;
					}
				}
				std::swap(dataArray[i], dataArray[highestIndex]);
			}
			return true;
		}
		catch (const std::exception&)
		{
			return false;
		}
	}
	else {
		std::cout << "error:\n" << "Expected (a, A, d, D, 0, 1), recieved" << order;
		return false;
	}
}

#endif // !SLECTION_SORT