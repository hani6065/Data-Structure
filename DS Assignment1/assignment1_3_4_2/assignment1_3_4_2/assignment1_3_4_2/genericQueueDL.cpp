#include<iostream>
#include "genericQueueDL.h"
using namespace std;

template <typename T>
listClass<T>::listClass()
{
	Count = 0;
	Head = NULL;
	Tail = NULL;
}

template <typename T>
listClass<T>::listClass(const listClass<T> &L)
{
	Count = L.Count;
	if (L.Head == NULL)
	{
		Head = NULL;
	}

	else
	{
		Head = new nodeRecord<T>;
		Head->Data = L.Head->Data;
		nodeRecord<T>* temp1 = Head;
		nodeRecord<T>* temp2 = Tail;
		for (Tail = L.Head->Next; temp2 != NULL; temp2 = temp2->Next)
		{
			temp1->Next = new nodeRecord<T>;
			temp1 = temp1->Next;
			temp1->Data = temp2->Data;
		}
		temp1->Next = NULL;
	}
}

template <typename T>
listClass<T>::~listClass()
{
	while (!isEmpty())
	{
		Delete(1);
	}
}

template <typename T>
void listClass<T>::Insert(int Position, T Item)
{
	if ((Position > Count + 1) || (Position < 1))
	{
		cout << "Position out of Range" << endl;
	}
	else
	{
		nodeRecord<T>* p = new nodeRecord<T>;
		p->Data = Item;

		if (Position == 1)
		{
			p->Next = Head;
			Head = p;
		}
		else
		{
			nodeRecord<T> *temp = Head;
			for (int i = 1; i < (Position - 1); i++)
			{
				temp = temp->Next;
			}
			p->Next = temp->Next;
			temp->Next = p;
		}
		Count++;
	}
}

template <typename T>
void listClass<T>::Delete(int Position)
{
	if ((Position > Count + 1) || (Position < 1))
	{
		cout << "Position out of Range" << endl;
	}
	else
	{
		nodeRecord<T>* temp = Head;
		nodeRecord<T>* temp2 = Head;

		if (Position == 1)
		{
			temp = Head;
			Head = Head->Next;
		}

		for (int i = 1; i < (Position - 1); ++i)
		{
			temp = temp->Next;
		}
		for (int i = 1; i < (Position); ++i)
		{
			temp2 = temp2->Next;
		}
		temp->Next = temp2->Next;
		temp = temp2;

		Count--;
	}
}

template <typename T>
void listClass<T>::Display()
{
	nodeRecord<T>* temp;
	temp = Head;
	cout << "( ";
	while (temp != NULL)
	{
		cout << temp->Data << " ";
		temp = temp->Next;
	}
	cout << ")" << endl;
	delete(temp);
}

template <typename T>
void listClass<T>::Retrieve(int Position, T & item)
{
	int n = 1;
	nodeRecord<T>* p = Head;
	if (isEmpty()) return;
	else if (0 < Position && Position < Count + 1)
	{
		p = Head;
		while (n < Count + 1)
		{
			if (n == Position)
			{
				item = p->Data;
				break;
			}
			p = p->Next;
			n++;
		}
		cout << Position << "��° : " << item << endl;
	}
	else
		cout << "Position out of Range" << endl;
}

template <typename T>
bool listClass<T>::isEmpty()
{
	return(Count == 0);
}

template <typename T>
int listClass<T>::Length()
{
	return Count;
}

template <typename T>
queueClass<T>::queueClass() {}

template <typename T>
queueClass<T>::queueClass(const queueClass<T> &Q) {
	Rear = Q.Rear;
}

template <typename T>
queueClass<T>::~queueClass() {
	while (!IsEmpty())
		Remove();
}

template <typename T>
void queueClass<T>::Add(T Item) {
	Rear.Insert(Rear.Length() + 1, Item);
}

template <typename T>
void queueClass<T>::Remove() {
	if (IsEmpty())
		cout << "Queue is empty" << endl;
	else Rear.Delete(1);
}

template <typename T>
void queueClass<T>::Display() {
	Rear.Display();
}

template <typename T>
void queueClass<T>::GetFront(T& Item) {
	Rear.Retrieve(1, Item);
}

template <typename T>
void queueClass<T>::Retrieve3(int Position, T& Item) {
	Rear.Retrieve(Position, Item);
}

template <typename T>
bool queueClass<T>::IsEmpty() {
	return bool(Rear.isEmpty());
}