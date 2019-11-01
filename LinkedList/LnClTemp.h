#pragma once

template<typename  TElement>
class LinkedListClassTemp
{
protected:
	int length;
	bool isEmpty;

public:
	LinkedListClassTemp(int l, bool e);
	~LinkedListClassTemp();

	virtual void addelem(TElement number) = 0;			// ���������� ��������
	virtual void printList() const = 0;					// ����� ������
	virtual void deletelem(int ind) = 0;				// �������� ��������
	virtual TElement get_by_index(int i) const = 0;		// ������� �� �������
	int getLength() const;								// �������� �����
	bool getIsEmpty() const;							// �������� �� �������
	virtual void swap(int ind1, int ind2) = 0;

};

template<typename TElement>
inline int LinkedListClassTemp<TElement>::getLength() const
{
	return this->length;
}

template<typename TElement>
inline bool LinkedListClassTemp<TElement>::getIsEmpty() const
{
	return this->isEmpty;
}

template<typename TElement>
inline LinkedListClassTemp<TElement>::LinkedListClassTemp(int l, bool e): length(l), isEmpty(e)
{

}

template<typename TElement>
inline LinkedListClassTemp<TElement>::~LinkedListClassTemp()
{

}
