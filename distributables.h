#pragma once

#ifndef NODE
#define NODE
#define NULL 0

template <class type>
class node
{
public:
	node();

	node(type input);

	type data;

	node* next;

	node* previous;
};

template <class type>
node<type>::node() {
	this->next = NULL;
	this->previous = NULL;
}

template <class type>
node<type>::node(type input) {
	this->data = input;
	this->next = NULL;
	this->previous = NULL;
}

#endif // !NODE

#ifndef ARRAY_PRINT
#define ARRAY_PRINT

template<typename type, typename type2>
class arrayPrint
{
public:
	void print(type dataArray[], int lenDataArray, type2 orientation);

protected:

};

/*
 * print
 * pre-condition: recieves an array of data
 * pre-condition: recieves an intiger representing how long the array is
 * pre-condition: a string or intiger tellig the algorithm to sort in assending or decending order
 * post-condition: prints list to cli given preconditions
 */
template<typename type, typename type2>
inline void arrayPrint<type, type2>::print(type dataArray[], int lenDataArray, type2 orientation)
{
	if (orientation == 'h' || orientation == 'H' || orientation == 0) {
		for (int n = 0; n < lenDataArray; n++) {
			if (n == lenDataArray - 1) {
				std::cout << dataArray[n] << std::endl;
			}
			else
				std::cout << dataArray[n] << ", ";
		}
	}
	else if (orientation == 'v' || orientation == 'V' || orientation == 1) {
		for (int n = 0; n < lenDataArray; n++) {
			std::cout << dataArray[n] << std::endl;
		}
	}
	else {
		std::cout << "error:\nExpected (h, H, v, V, 0, 1), recieved: " << orientation;
	}
}

#endif // !ARRAY_PRINT
