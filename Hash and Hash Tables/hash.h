#pragma once

#ifndef HASH
#define HASH

template<typename type>
class hashFunction
{
public:
	hashFunction();
protected:
	int hashCustom(type input);

	int hashFIA(type input, int buckets);

	int hashPOTen(type input, int power);

	int hashPOTwo(type input, int power);

	int hashTen(type input);

	int hashHundred(type input);

};

template<typename type>
inline hashFunction<type>::hashFunction()
{
}

template<typename type>
inline int hashFunction<type>::hashCustom(type input)
{
	return input % 10;
}

template<typename type>
inline int hashFunction<type>::hashFIA(type input, int buckets)
{
	return input % buckets;
}

template<typename type>
inline int hashFunction<type>::hashPOTen(type input, int power)
{
	int pow = 1;
	for (int n = 1; n < power; n++)
	{
		pow = pow * 10;
	}
	return input % pow;
}

template<typename type>
inline int hashFunction<type>::hashPOTwo(type input, int power)
{
	int pow = 1;
	for (int n = 1; n < power; n++)
	{
		pow = pow * 2;
	}
	return input % pow;
}

template<typename type>
inline int hashFunction<type>::hashTen(type input)
{
	return input % 10;
}

template<typename type>
inline int hashFunction<type>::hashHundred(type input)
{
	return input % 100;
}

#endif // !HASH