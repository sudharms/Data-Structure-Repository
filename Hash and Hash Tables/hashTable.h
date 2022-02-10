#pragma once
#include "hash.h"
#include "../distributables.h"

#ifndef HASH_TABLE
#define HASH_TABLE

template<typename type, int numBuckets>
class hashTable : public hashFunction
{
public:
	hashTable();

	bool addItem(int key, type data);

protected:
	node* table[numBuckets];
};

#endif // !HASH_TABLE
