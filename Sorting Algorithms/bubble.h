#pragma once

#ifndef BUBBLE_SORT
#define BUBBLE_SORT

template<typename type, typename type2>
class Bubble
{
public:
	bool sort(type dataArray[], int lenDataArray, type2 order);
};

#endif // !BUBBLE_SORT

template<typename type, typename type2>
inline bool Bubble<type, type2>::sort(type dataArray[], int lenDataArray, type2 order)
{
	if (order == 'a' || order == 'A' || order == 1)
	{
		try
		{
			bool loop = true;
			int swaps = 0;
			for (int i = lenDataArray; i > 0 && loop == true; i--) {
				for (int n = 0; n < (lenDataArray - 1); n++) {
					if (dataArray[n] > dataArray[n + 1]) {
						std::swap(dataArray[n], dataArray[n + 1]);
						swaps++;
					}
				}
				if (swaps == 0) {
					loop = false;
				}
				else {
					swaps = 0;
				}
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
			bool loop = true;
			int swaps = 0;
			for (int i = lenDataArray; i > 0 && loop == true; i--) {
				for (int n = 0; n < (lenDataArray - 1); n++) {
					if (dataArray[n] < dataArray[n + 1]) {
						std::swap(dataArray[n], dataArray[n + 1]);
						swaps++;
					}
				}
				if (swaps == 0) {
					loop = false;
				}
				else {
					swaps = 0;
				}
			}
			return true;
		}
		catch (const std::exception&)
		{
			return false;
		}
	}
	else {
		std::cout << "error:\n" << "Expected (a, A, d, D, 0, 1), recieved: " << order;
		return false;
	}
}
