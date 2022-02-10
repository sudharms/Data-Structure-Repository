#pragma once
#include "debug base.h"

#ifndef DEBUGGING_TOOLS
#define DEBUGGING_TOOLS

template<typename type, int len>
class debuggingTools
{
public:
	void randomise(type dataArray[], int len);

	bool arrayCompairisonTest(type knownGood[], type test[]);
};

template<typename type, int len>
inline void debuggingTools<type, len>::randomise(type dataArray[], int dataArraylen)
{
	std::shuffle(dataArray, dataArray + dataArraylen, std::default_random_engine(0));
}

template<typename type, int len>
inline bool debuggingTools<type, len>::arrayCompairisonTest(type knownGood[], type test[])
{
	int typeOutput[3][len]{};
	int output[3][len]{};
	int errors = 0;
	for (int n = 0; n < len; n++)
	{
		typeOutput[0][n] = knownGood[n];
		output[0][n] = 1;

		typeOutput[1][n] = test[n];
		output[1][n] = 1;
		if (knownGood[n] == test[n])
		{
			typeOutput[2][n] = knownGood[n];
			output[2][n] = 1;
		}
		else
		{
			typeOutput[2][n] = -911;
			output[2][n] = 0;
			errors++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		cout << endl;
		cout << "|";
		for (int k = 0; k < len; k++)
		{
			if (k > 0) cout << " ";
			std::cout << typeOutput[i][k];
			if (k == len - 1) cout << "|";
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
	{
		cout << endl;
		cout << "|";
		for (int k = 0; k < len; k++)
		{
			if (k > 0) cout << " ";
			std::cout << output[i][k];
			if (k == len - 1) cout << "|";
		}
	}
	if (errors == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

#endif // !DEBUGGING_TOOLS