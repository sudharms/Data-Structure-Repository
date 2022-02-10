#pragma once

#ifndef VLDEBUGGING
#define VLDEBUGGING

/*
* template<int len>
* debugingVL
* WARNING: FOR LETTER USAGE, MAX LENGTH FOR LEN IS 26!
*/
template<int len>
class debugingVL : public debugingSL
{
public:
	debugingVL(bool init);

	int VLnumbersUnsorted[len]{};
	int VLnumbersSortedAcending[len]{};
	int VLnumbersSortedDecending[len]{};

	char VLlettersUpperUnsorted[len]{};
	char VLlettersUpperSortedAcending[len]{};
	char VLlettersUpperSortedDecending[len]{};

	char VLlettersLowerUnsorted[len]{};
	char VLlettersLowerSortedAcending[len]{};
	char VLlettersLowerSortedDecending[len]{};

	char VLlettersMixUnsorted[len]{};
	char VLlettersMixSortedAcending[len]{};
	char VLlettersMixSortedDecending[len]{};

	bool initNums();

	bool initUpperLetters();

	bool initLowerLetters();

	bool initMixLetters();

private:
	int initLeterTest(bool mixed);

	bool initLeter(char sorted[], char sortedDecending[], char unsorted[], int lowerAscii, bool mixed);
};

template<int len>
inline int debugingVL<len>::initLeterTest(bool mixed)
{
	if (mixed)
	{
		if (len <= 26*2)
			return len;
		else
			return 26*2;
	}
	else
	{
		if (len <= 26)
			return len;
		else
			return 26;
	}
}

template<int len>
inline bool debugingVL<len>::initLeter(char sortedAcending[], char sortedDecending[], char unsorted[], int lowerAscii, bool mixed)
{
	try
	{
		if (mixed)
		{
			int ilt = initLeterTest(true);
			for (int n = 0, ascii = 65; n < ilt; n++, ascii++)
			{
				if (ascii > 90 && ascii < 97)
				{
					ascii = 97;
				}
				unsorted[n] = ascii;
				sortedAcending[n] = ascii;
				sortedDecending[(ilt - 1) - n] = ascii;
			}
			std::shuffle(unsorted, unsorted + ilt, std::default_random_engine(0));
			return true;
		}

		else
		{
			int ilt = initLeterTest(false);
			for (int n = 0, ascii = lowerAscii; n < ilt; n++, ascii++)
			{
				unsorted[n] = ascii;
				sortedAcending[n] = ascii;
				sortedDecending[(ilt - 1) - n] = ascii;
			}
			std::shuffle(unsorted, unsorted + ilt, std::default_random_engine(0));
			return true;
		}
	}
	catch (const std::exception&)
	{
		return false;
	}
}

template<int len>
inline bool debugingVL<len>::initNums()
{
	try
	{
		for (int n = 0; n < len; n++)
		{
			VLnumbersUnsorted[n] = n;
			VLnumbersSortedAcending[n] = n;
			VLnumbersSortedDecending[(len - 1) - n] = n;
		}

		std::shuffle(VLnumbersUnsorted, VLnumbersUnsorted +len, std::default_random_engine(0));

		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

template<int len>
inline bool debugingVL<len>::initUpperLetters()
{
	bool result = initLeter(VLlettersUpperSortedAcending, VLlettersUpperSortedDecending, VLlettersUpperUnsorted, 65, false);
	if (result)
	{
		std::cout << "Upper Letter Array Created\n";
		return true;
	}
	else
	{
		std::cout << "Upper Letter Array NOT Created\n";
		return false;
	}
}

template<int len>
inline bool debugingVL<len>::initLowerLetters()
{
	bool result = initLeter(VLlettersLowerSortedAcending, VLlettersLowerSortedDecending, VLlettersLowerUnsorted, 97, false);
	if (result)
	{
		std::cout << "Lower Letter Array Created\n";
		return true;
	}
	else
	{
		std::cout << "Lower Letter Array NOT Created\n";
		return false;
	}
}

template<int len>
inline bool debugingVL<len>::initMixLetters()
{
	bool result = initLeter(VLlettersMixSortedAcending, VLlettersMixSortedDecending, VLlettersMixUnsorted, 65, true);
	if (result)
	{
		std::cout << "Mixed Letter Array Created\n";
		return true;
	}
	else
	{
		std::cout << "Mixed Letter Array NOT Created\n";
		return false;
	}
}

template<int len>
inline debugingVL<len>::debugingVL(bool init)
{
	if (init)
	{
		initNums();
		initUpperLetters();
		initLowerLetters();
		initMixLetters();
	}
}

#endif // !VLDEBUGGING