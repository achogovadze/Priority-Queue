/*************************************************************
* File: pqueue-linkedlist.cpp
*
* Implementation file for the LinkedListPriorityQueue
* class.
*/

#include "pqueue-linkedlist.h"
#include "error.h"

LinkedListPriorityQueue::LinkedListPriorityQueue() {
	head = new Node;
	tail = new Node;
	head -> next = tail;
	tail -> next = NULL;
	counter = 0;
}

void LinkedListPriorityQueue::freeList(Node* start){
	if (start == NULL)
		return;
	freeList(start -> next);
	delete start;
}

LinkedListPriorityQueue::~LinkedListPriorityQueue() {
	freeList(head);
}

int LinkedListPriorityQueue::size() {
	return counter;
}

bool LinkedListPriorityQueue::isEmpty() {
	return counter == 0;
}

void LinkedListPriorityQueue::enqueue(string value) {
	if (head -> next == tail){
		Node* newNode = new Node;
		newNode -> value = value;
		head -> next = newNode;
		newNode -> next = tail;
	} else {
		Node* first = head;
		while (first -> next != tail && first -> next -> value < value){
			first = first -> next;
		}
		Node* newNode = new Node;
		Node* tmp = first -> next;
		first -> next = newNode;
		newNode -> next = tmp;
		newNode -> value = value;
	}
	counter++;
}

string LinkedListPriorityQueue::peek() {
	if (isEmpty())
		error ("ERROR");
	return head -> next -> value;
}

string LinkedListPriorityQueue::dequeueMin() {
	string result = peek();
	Node* tmp = head -> next;
	head -> next = head -> next -> next;
	delete tmp;
	counter--;
	return result;
}

