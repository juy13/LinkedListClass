#pragma once
#include <iostream>


// структура - элемент списка, является шаблонной и может принимать любой тип данных
template<typename  TElement>
struct list {
	TElement field;
	struct list<TElement> *ptr;
};

template<typename  TElement>
class LinkedListClass
{
private:
	list<TElement> *head;		// указатель на начало списка
	int len = 0;				// длина списка

	list<TElement> * Get(int i) const;			// по индексу получаем указатель на элемент структуры, нужен для удаления по индексу
	list<TElement> * Prev(list<TElement> * node) const;	// по индексу получаем указатель на элемент структуры, который предыдущий пришедшему, нужен для удаления по индексу
	bool isEmpty() const;		// проверка на пустоту

public:
	LinkedListClass();
	~LinkedListClass();
	
	void addelem(TElement number);			// добавление элемента
	void printList() const;					// вывод списка
	void deletelem(int ind);				// удаление элемента
	TElement Get_by_index(int i) const;		// достать по индексу
	int Get_len() const;					// получить длину
};

template<typename TElement>
inline list<TElement>* LinkedListClass<TElement>::Get(int i) const
{
	if (i < 0 || i >= this->len)
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
inline TElement LinkedListClass<TElement>::Get_by_index(int i) const
{
	if (i < 0 || i >= this->len)
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
inline int LinkedListClass<TElement>::Get_len() const
{
	list<TElement> *temp = head;
	int ind = 0;
	while (temp->ptr != nullptr)
	{
		temp = temp->ptr;
		ind++;
	}
	return (ind + 1);
}

template<typename TElement>
inline list<TElement>* LinkedListClass<TElement>::Prev(list<TElement>* node) const
{
	if (isEmpty()) 
		throw std::exception("No elements");	 // В списке нет узлов
	if (node == this->head) 
		throw std::exception("No previos elements");	 // В списке нет узлов
	list<TElement> *p = head;
	while (p->ptr != node)
		p = p->ptr;
	return p;
}

template<typename TElement>
inline bool LinkedListClass<TElement>::isEmpty() const
{
	if (this->head == NULL)
		return true;
	else
		return false;
}

template<typename TElement>
LinkedListClass<TElement>::LinkedListClass()
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
		this->head = nd;
	else											//если узел уже не первый
	{
		list<TElement> *current = head;
													//ищем в цикле предшествующий последнему узел
		while (current->ptr != nullptr)
			current = current->ptr;
													//предшествующий указывает на последний
		current->ptr = nd;
	}
	this->len++;
}

template<typename TElement>
void LinkedListClass<TElement>::printList() const
{
	if (this->len == 0)
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
	if (ind < 0 || ind >= this->len)
		throw std::exception("Illegal index");
	list<TElement> * node = this->Get(ind);
	if (node == NULL) 
		throw std::exception("Nothing to delete");	 // В списке нет узлов
	if (node == this->head)							  // Удаление корневого узла
	{
		head = node->ptr;
		delete node;
		return;
	}
	list<TElement>* prev = this->Prev(node); // Удаление промежуточного узла
	prev->ptr = node->ptr;
	delete node;
}
