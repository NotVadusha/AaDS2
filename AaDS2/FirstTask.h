#pragma once
#include <iostream>

using namespace std;

template <class T>
struct LLNode {
	T data;
	LLNode <T>* next;
	LLNode <T>* prev;
};

template <class T>
void Push(LLNode <T>** head, T newData)
{
	LLNode <T>* newNode = new LLNode <T>();
	newNode->data = newData;
	newNode->next = (*head);
	newNode->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = newNode;
	(*head) = newNode;
}

template <class T>
void insertAfter(LLNode <T>* currentNode, T newData)
{
	if (currentNode == NULL)
	{
		cout << "the given previous node cannot be NULL";
		return;
	}

	LLNode <T>* newNode = new LLNode <T>();
	newNode->data = newData;
	newNode->next = currentNode->next;
	newNode->prev = currentNode;

	if (currentNode->next != NULL)
		currentNode->next->prev = newNode;

	currentNode->next = newNode;
}

template <class T>
LLNode <T>* deleteNode(LLNode <T>* head, LLNode <T>* nodeToDelete)
{
	LLNode <T>* currentNode = head, * prev = head;
	if (currentNode != NULL && currentNode == nodeToDelete)
	{
		head = currentNode->next;
		delete currentNode;
		return head;
	}

	while (currentNode != NULL && currentNode != nodeToDelete)
	{
		prev = currentNode;
		currentNode = currentNode->next;
	}

	if (currentNode == NULL) return head;

	prev->next = currentNode->next;
	delete currentNode;
	return head;
}

template <class T>
void freeMemory(LLNode <T>* head)
{
	LLNode <T>* currentNode = head;
	while (currentNode != NULL)
	{
		head = currentNode->next;
		delete currentNode;
		currentNode = head;
	}
}

template <class T>
void printList(LLNode <T>* node)
{
	LLNode <T>* last;
	cout << "\nTraversal in forward direction \n";
	while (node != NULL)
	{
		cout << node->data << " ";
		last = node;
		node = node->next;
	}
	cout << endl;
}

void  FirstTask()
{
	LLNode <char>* head = NULL, * currentNode = NULL;
	const int N = 10;
	char input;

	cout << endl << "Input " << N << " chars: " << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		if (head == NULL) {
			head = new LLNode<char>();
			head->data = input;
			head->next = NULL;
			head->prev = NULL;
			currentNode = head;
		}
		else {
			insertAfter(currentNode, input);
			currentNode = currentNode->next;
		}
	}
	cout << "Created list is: ";
	printList(head);

	currentNode = head;
	while (currentNode != NULL)
	{
		if (currentNode->data < 48)
		{
			head = deleteNode(head, currentNode);
			break;
		}
		currentNode = currentNode->next;
	}

	currentNode = head;
	while (currentNode != NULL)
	{
		if (currentNode->data > 47 && currentNode->data < 57)
		{
			insertAfter(currentNode, '%');
		}
		currentNode = currentNode->next;
	}

	cout << "\nModified list is: ";
	printList(head);

	freeMemory(head);
}
