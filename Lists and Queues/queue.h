#pragma once
#include <exception>
#include "../distributables.h"

#ifndef QUEUE
#define QUEUE

template<typename type, type errorValue>
class queue
{
public:
	queue();

	queue(type data);

	bool add(type data);

	bool contains(type target);

	type remove();
protected:
	node<type>* front;

	node<type>* rear;
};

template<typename type, type errorValue>
inline queue<type, errorValue>::queue()
{
	this->rear = NULL;
	this->front = NULL;
}

template<typename type, type errorValue>
inline queue<type, errorValue>::queue(type data)
{
	node<type>* temp = new node<type>(data);
	this->rear = temp;
	this->front = temp;
	temp = NULL;
}

template<typename type, type errorValue>
inline bool queue<type, errorValue>::add(type data)
{
	try
	{
		node<type>* temp = new node<type>(data);
		if (front == NULL)
		{
			this->front = temp;
		}
		else
		{
			rear->next = temp;
			temp->previous = rear;
		}
		this->rear = temp;
		temp = NULL;
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

template<typename type, type errorValue>
inline bool queue<type, errorValue>::contains(type target)
{
	node<type>* current = rear;
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
inline type queue<type, errorValue>::remove()
{
	try
	{
		type value = front->data;
		node<type>* temp = front;
		if (front != rear)
		{
			this->front = front->previous;
			front->next = NULL;
		}
		else if (front == rear)
		{
			this->front = NULL;
			this->rear = NULL;
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

#endif // !QUEUE