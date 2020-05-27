/*************************************************************
* File: pqueue-heap.cpp
*
* Implementation file for the HeapPriorityQueue
* class.
*/

#include "pqueue-heap.h"
#include "error.h"

#define STARTING_SIZE 10;

HeapPriorityQueue::HeapPriorityQueue() {
	logLen = 0;
	allocLen = STARTING_SIZE;
	arr = new string[allocLen];
}

HeapPriorityQueue::~HeapPriorityQueue() {
	delete [] arr;
}

int HeapPriorityQueue::size() {
	return logLen;
}

bool HeapPriorityQueue::isEmpty() {
	return logLen == 0;
}

void HeapPriorityQueue::enqueue(string value) {
	if (logLen == allocLen)
		grow();
	arr[logLen] = value;
	logLen++;
	bubbleUp(logLen);
}

string HeapPriorityQueue::peek() {
	if (isEmpty())
		error("ERROR");
	//for (int i = 0; i < logLen; i++){
	//	cout << arr[i] << endl;
	//}
	return arr[0];
}

string HeapPriorityQueue::dequeueMin() {
	string result = peek();
	arr[0] = arr[logLen - 1];
	arr[logLen - 1] = result;
	logLen--;
	bubbleDown();
	return result;
}

void HeapPriorityQueue::grow(){
	allocLen *= 2;
	string* tmp = new string[allocLen];
	for (int i = 0; i < logLen; i++){
		tmp[i] = arr[i];
	}
	delete [] arr;
	arr = tmp;
}

void HeapPriorityQueue::bubbleUp(int index){
	index--;
	int upIndex = (index - 1) / 2;
	while (arr[index] < arr[upIndex]){
		if (index < 1)
			return;
		string tmp = arr[index];
		arr[index] = arr[upIndex];
		arr[upIndex] = tmp;
		index = upIndex;
		upIndex = (index - 1) / 2;
	}
}

void HeapPriorityQueue::bubbleDown(){
	int startIndex = 0;
	int prev = 0;
	while (startIndex * 2 + 2 < logLen){
		prev = startIndex;
		if (arr[startIndex * 2 + 1] < arr[startIndex * 2 + 2]){
			startIndex = startIndex * 2 + 1;
		} else {
			startIndex = startIndex * 2 + 2;
		}
		if (arr[prev] > arr[startIndex]){
			string tmp = arr[startIndex];
			arr[startIndex] = arr[prev];
			arr[prev] = tmp;
		}
	}
	prev = startIndex;
	startIndex = startIndex * 2 + 1;
	if (startIndex < logLen){
		if (arr[prev] > arr[startIndex]){
			string tmp = arr[startIndex];
			arr[startIndex] = arr[prev];
			arr[prev] = tmp;
		}
	}
}
