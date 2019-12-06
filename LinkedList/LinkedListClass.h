#pragma once
#include <iostream>
#include "LnClTemp.h"



// структура - элемент списка, является шаблонной и может принимать любой тип данных
template<typename  TElement>
struct list {
	TElement field;
	struct list<TElement> *ptr;
	//const bool operator>(const TElement rgt);
};

template<typename  TElement>
class LinkedListClass: public LinkedListClassTemp<TElement>
{
private:
	list<TElement> *head;		// указатель на начало списка

	list<TElement> * get(int i) const;			// по индексу получаем указатель на элемент структуры, нужен для удаления по индексу
	list<TElement> * prev(list<TElement> * node) const;	// по индексу получаем указатель на элемент структуры, который предыдущий пришедшему, нужен для удаления по индексу
	//bool isEmpty() const;		// проверка на пустоту
	void swap_in(TElement& x, TElement& y)
	{
		TElement tmp{ std::move(x) }; // вызывает конструктор перемещения
		x = std::move(y); // вызывает оператор присваивания перемещением
		y = std::move(tmp); // вызывает оператор присваивания перемещением
	}

public:
	LinkedListClass();
	~LinkedListClass();
	
	virtual void addelem(TElement number) override;			// добавление элемента
	virtual void printList() const override;				// вывод списка
	virtual void deletelem(int ind) override;				// удаление элемента
	virtual TElement get_by_index(int i) const override;	// достать по индексу
	virtual void swap(int ind1, int ind2) override;
	TElement& operator[](int i);


};

template<typename TElement>
const bool operator>(const TElement lft, const TElement rgt)
{
	if (lft < rgt)
		return false;
	else
		return true;
}

template<typename TElement>
inline list<TElement>* LinkedListClass<TElement>::get(int i) const
{
	if (i < 0 || i >= this->getLength())
		throw std::exception("Illegal index");
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
inline TElement LinkedListClass<TElement>::get_by_index(int i) const
{
	if (i < 0 || i >= this->getLength())
		throw std::exception("Illegal index");
	list<TElement> *temp = head;
	int ind = 0;
	while (i != ind)
	{
		temp = temp->ptr;
		ind++;
	}
	return temp->field;
}

template<typename TElement>
inline void LinkedListClass<TElement>::swap(int ind1, int ind2)
{
	list<TElement> *lst1;
	list<TElement> *lst2;
	try
	{
		lst1 = this->get(ind1);
		lst2 = this->get(ind2);
	}
	catch (const std::exception&ex)
	{
		throw std::exception(ex.what());
	}
	this->swap_in(lst1->field, lst2->field);
}


template<typename TElement>
inline list<TElement>* LinkedListClass<TElement>::prev(list<TElement>* node) const
{
	if (!this->getIsEmpty())
		throw std::exception("No elements");	 // В списке нет узлов
	if (node == this->head) 
		throw std::exception("No previos elements");	 // В списке нет узлов
	list<TElement> *p = head;
	while (p->ptr != node)
		p = p->ptr;
	return p;
}

template<typename TElement>
inline TElement &LinkedListClass<TElement>::operator[](int i)
{
	try
	{
		list<TElement> *tmp = get(i);
		return tmp->field;
	}
	catch (const std::exception& ex)
	{
		throw std::exception(ex.what());
	}
}



template<typename TElement>
LinkedListClass<TElement>::LinkedListClass(): LinkedListClassTemp<TElement>(0, false)
{
	this->head = nullptr;
}

template<typename TElement>
LinkedListClass<TElement>::~LinkedListClass()
{
	int i = 0;
	while (this->head)
	{
		this->deletelem(i);				// очистка класса от элементов
	}
}

template<typename TElement>
void LinkedListClass<TElement>::addelem(TElement number)
{
	list<TElement> *nd = new list<TElement>;		  //динамически создаем новый узел
	nd->field = number;								 //задаем узлу данные
	nd->ptr = nullptr;								 //новый узел в конце, поэтому NULL
	if (this->head == nullptr)						 //если создаем первый узел
	{
		this->head = nd;
		this->isEmpty = true;
	}
		
	else											//если узел уже не первый
	{
		list<TElement> *current = head;
													//ищем в цикле предшествующий последнему узел
		while (current->ptr != nullptr)
			current = current->ptr;
													//предшествующий указывает на последний
		current->ptr = nd;
	}
	this->LinkedListClassTemp<TElement>::length++;
}

template<typename TElement>
void LinkedListClass<TElement>::printList() const
{
	if (this->getLength() == 0)
		throw std::exception("Nothing to print");
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
	if (ind < 0 || ind >= this->getLength())
		throw std::exception("Illegal index");
	list<TElement> * node = this->get(ind);
	if (node == NULL) 
		throw std::exception("Nothing to delete");	 // В списке нет узлов
	if (node == this->head)							  // Удаление корневого узла
	{
		this->LinkedListClassTemp<TElement>::length--;
		this->LinkedListClassTemp<TElement>::isEmpty = false;
		head = node->ptr;
		delete node;
		return;
	}
	list<TElement>* prev = this->prev(node); // Удаление промежуточного узла
	prev->ptr = node->ptr;
	this->LinkedListClassTemp<TElement>::length--;
	delete node;
}
