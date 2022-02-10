#pragma once
#include <exception>
#include "../distributables.h"

#ifndef STACK
#define STACK

template<typename type, type errorValue>
class stack
{
public:
	stack();

	stack(type data);

	bool push(type data);

	bool contains(type target);
	
	type pop();
protected:
	node<type>* bottom;

	node<type>* top;
};

template<typename type, type errorValue>
inline stack<type, errorValue>::stack()
{
	this->top = NULL;
	this->bottom = NULL;
}

template<typename type, type errorValue>
inline stack<type, errorValue>::stack(type data)
{
	node<type>* temp = new node<type>(data);
	this->top = temp;
	this->bottom = temp;
	temp = NULL;
}

template<typename type, type errorValue>
inline bool stack<type, errorValue>::push(type data)
{
	try
	{
		node<type>* temp = new node<type>(data);
		if (bottom == NULL)
		{
			this->bottom = temp;
		}
		else
		{
			top->next = temp;
			temp->previous = top;
		}
		this->top = temp;
		temp = NULL;
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

template<typename type, type errorValue>
inline bool stack<type, errorValue>::contains(type target)
{
	node<type>* current = top;
	while (current != NULL)
	{
		if (current->data == target)
		{
			return true;
		}
		else
		{
			current = current->previous;
		}
	}
	return false;
}

template<typename type, type errorValue>
inline type stack<type, errorValue>::pop()
{
	try
	{
		type value = top->data;
		node<type>* temp = top;
		if (top != bottom)
		{
			this->top = top->previous;
			top->next = NULL;
		}
		else if (top == bottom)
		{
			this->top = NULL;
			this->bottom = NULL;
		}
		else
		{
			return errorValue;
		}
		delete temp;
		temp = NULL;
		return value;
	}
	catch (const std::exception&)
	{
		return errorValue;
	}
}

#endif // !STACK