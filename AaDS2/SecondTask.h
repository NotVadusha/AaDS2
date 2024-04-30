#pragma once
#include <iostream>

template <class T>
struct CLNode {
	T data;
	CLNode<T>* next;
};

using namespace std;

template <class T>
CLNode<T>* InitList(T x)
{
	CLNode<T>* currentNode = new CLNode<T>;
	currentNode->next = currentNode;
	currentNode->data = x;
	return currentNode;
}


template <class T>
CLNode<T>* AddNodeAfter(CLNode<T>*& ptr, T x)
{
	CLNode<T>* currentNode = new CLNode<T>;
	currentNode->next = currentNode;
	currentNode->data = x;
	if (ptr == NULL) return NULL;

	else
	{
		currentNode->next = ptr->next;
		ptr->next = currentNode;
		ptr = currentNode;
		return currentNode->next;
	}
}


template <class T>
void Print_Right(CLNode<T>* head)
{
	cout << "The list from head to end:" << endl;
	if (head == NULL)
	{
		cout << "Empty" << endl; return;
	}
	CLNode<T>* currentNode = head;
	while (currentNode != NULL)
	{
		cout << currentNode->data << " ";
		currentNode = currentNode->next;
	}
	cout << endl;
}

template <class T>
void Print_List(CLNode<T>* head)
{
	cout << "The list:" << endl;
	CLNode<T>* currentNode = head;
	do {
		if (currentNode) {
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
	} while (currentNode != head);
	cout << endl;
}

template <class T>
void Free_Memory(CLNode<T>* head, CLNode<T>* end)
{
	if (head == NULL) return;
	CLNode<T>* currentNode = head;
	end->next = NULL;
	while (currentNode != NULL)
	{
		head = head->next;
		delete currentNode;
		currentNode = head;
	}
}

template <class T>
CLNode<T>* DeleteNode(CLNode<T>* ptr, CLNode<T>* head, CLNode<T>* end)
{
	if (ptr == NULL) return NULL;
	if (ptr == head)
	if (ptr == head)
	{
		if (head == end)
		{
			delete ptr;
			head = end = NULL;
			return NULL;
		}
		else
		{
			head = head->next;
			end->next = head;
			delete ptr;
			return head;
		}
	}
	CLNode<T>* prev = ptr->next;
	while (prev && prev->next != ptr)
		prev = prev->next;
	if (prev != ptr)
	{
		prev->next = ptr->next;
		if (ptr == end) end = prev;
		delete ptr;
		return prev->next;
	}
	return NULL;
}


void SecondTask()
{
	CLNode<int>* head = NULL, * end = NULL, * currentNode; int input;
	CLNode<int>* max = NULL;

	const int N = 10;
	cout << "Input " << N << " integers:" << endl;
	for (int i = 1; i <= N; i++)
	{
		cin >> input;
		if (head == NULL) head = end = InitList<int>(input);
		else head = AddNodeAfter<int>(end, input);
	}
	Print_List<int>(head);

	currentNode = head;
	max = head;
	do
	{
		if (currentNode->data > max->data) max = currentNode;
		currentNode = currentNode->next;
	} while (currentNode != head);
	cout << "\nMax value: " << max->data << endl;

	int maxData = max->data;
	currentNode = head;
	do
	{
		currentNode->data = currentNode->data + maxData;
		currentNode = currentNode->next;
	} while (currentNode != head);

	currentNode = head;
	Print_List<int>(head);
}