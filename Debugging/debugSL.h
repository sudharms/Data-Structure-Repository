#pragma once
#include "debug base.h"

#ifndef SLDEBUGGING
#define SLDEBUGGING

class debugingSL
{
public:
	int SLnumbersUnsorted[10] = { 4, 5, 7, 1, 3, 6, 2, 8, 0, 9 };
	int SLnumbersSortedAcending[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int SLnumbersSortedDecending[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	char SLlettersUpperUnsorted[10] = { 'D', 'E', 'G', 'A', 'C', 'F', 'B', 'H', 'J', 'I' };
	char SLlettersUpperSortedAcending[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	char SLlettersUpperSortedDecending[10] = { 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A' };

	char SLlettersLowerUnsorted[10] = { 'd', 'e', 'g', 'a', 'c', 'f', 'b', 'h', 'j', 'i' };
	char SLlettersLowerSortedAcending[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
	char SLlettersLowerSortedDecending[10] = { 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a' };

	char SLlettersMixUnsorted[10] = { 'd', 'E', 'G', 'A', 'C', 'f', 'b', 'h', 'j', 'I' };
	char SLlettersMixSortedAcending[10] = { 'A', 'b', 'C', 'd', 'E', 'f', 'G', 'h', 'I', 'j' };
	char SLlettersMixSortedDecending[10] = { 'j', 'I', 'h', 'G', 'f', 'E', 'd', 'C', 'b', 'A' };
};

#endif // !SLDEBUGGING