#pragma once
#include <iostream>



template<typename  TElement>
struct list {
	TElement field;
	struct list<TElement> *ptr;
};

template<typename  TElement>
class LinkedListClass
{
private:
	list<TElement> *head;
	int len = 0;
	list<TElement> * Get(int i) const;
	list<TElement> * Prev(list<TElement> * node) const;
	bool isEmpty() const;

public:
	LinkedListClass();
	~LinkedListClass();
	
	void addelem(TElement number);
	void printList() const;
	void deletelem(int ind);
	//void deletehead();
	//void listprint();
};

template<typename TElement>
inline list<TElement>* LinkedListClass<TElement>::Get(int i) const
{
	list<TElement> *temp = head;
	int ind = 0;
	while (i != ind)
	{
		temp = temp->ptr;
		ind++;
	}
	return temp;
}

template<typename TElement>
inline list<TElement>* LinkedListClass<TElement>::Prev(list<TElement>* node) const
{
	if (isEmpty()) 
		return NULL;
	if (node == this->head) 
		return NULL;
	list<TElement> *p = head;
	while (p->ptr != node)
		p = p->ptr;
	return p;
}

template<typename TElement>
inline bool LinkedListClass<TElement>::isEmpty() const
{
	if (this->head == NULL)
		return false;
	else
		return true;
}

template<typename TElement>
LinkedListClass<TElement>::LinkedListClass()
{
	this->head = nullptr;
}

template<typename TElement>
LinkedListClass<TElement>::~LinkedListClass()
{
}

template<typename TElement>
void LinkedListClass<TElement>::addelem(TElement number)
{
	list<TElement> *nd = new list<TElement>; //динамически создаем новый узел
	nd->field = number;        //задаем узлу данные
	nd->ptr = nullptr;     //новый узел в конце, поэтому NULL
	if (this->head == nullptr)     //если создаем первый узел
		this->head = nd;
	else                 //если узел уже не первый
	{
		list<TElement> *current = head;
		//ищем в цикле предшествующий последнему узел
		while (current->ptr != nullptr)
			current = current->ptr;
		//предшествующий указывает на последний
		current->ptr = nd;
	}
}

template<typename TElement>
void LinkedListClass<TElement>::printList() const
{
	list<TElement> *current = head;
	while (current != nullptr)
	{
		std::cout << current->field << std::endl;
		current = current->ptr;
	}
}

template<typename TElement>
inline void LinkedListClass<TElement>::deletelem(int ind)
{
	list<TElement> * node = this->Get(ind);
	if (node == NULL) { return; } // В списке нет узлов
	if (node == this->head)  // Удаление корневого узла
	{
		head = node->ptr;
		delete node;
		return;
	}
	list<TElement>* prev = this->Prev(node); // Удаление промежуточного узла
	prev->ptr = node->ptr;
	delete node;
}
