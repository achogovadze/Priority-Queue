/*************************************************************
* File: pqueue-doublylinkedlist.cpp
*
* Implementation file for the DoublyLinkedListPriorityQueue
* class.
*/

#include "pqueue-doublylinkedlist.h"
#include "error.h"

DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue() {
	head = new Node;
	tail = new Node;
	head -> next = tail;
	head -> prev = NULL;
	tail -> next = NULL;
	tail -> prev = head;
	counter = 0;
}

void DoublyLinkedListPriorityQueue::freeList(Node* start){
	if (start == NULL)
		return;
	freeList(start -> next);
	delete start;
}

DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue() {
	freeList(head);
}

int DoublyLinkedListPriorityQueue::size() {
	return counter;
}

bool DoublyLinkedListPriorityQueue::isEmpty() {
	return counter == 0;
}

void DoublyLinkedListPriorityQueue::enqueue(string value) {
	Node* newHead = new Node;
	head -> value = value;
	head -> prev = newHead;
	newHead -> next = head;
	head = newHead;
	counter++;
}

string DoublyLinkedListPriorityQueue::peek() {
	if (counter == 0)
		error("ERROR");
	Node* cur = head -> next;
	string result = cur -> value;
	while (cur -> next != tail){
		cur = cur -> next;
		if (cur -> value < result){
			result = cur -> value;
		}
	}
	return result;
}

string DoublyLinkedListPriorityQueue::dequeueMin() {
	if (counter == 0)
		error("ERROR");
	Node* cur = head -> next;
	string result = cur -> value;
	Node* toDelete = cur;
	while (cur -> next != tail){
		cur = cur -> next;
		if (cur -> value < result){
			result = cur -> value;
			toDelete = cur;
		}
	}
	toDelete -> prev -> next = toDelete -> next;
	toDelete -> next -> prev = toDelete -> prev;
	delete toDelete;
	counter--;
	return result;
}

