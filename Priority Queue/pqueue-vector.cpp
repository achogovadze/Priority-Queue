/*************************************************************
 * File: pqueue-vector.cpp
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */
 
#include "pqueue-vector.h"
#include "error.h"

VectorPriorityQueue::VectorPriorityQueue() {
	// TODO: Fill this in!
}

VectorPriorityQueue::~VectorPriorityQueue() {
	// TODO: Fill this in!
}

int VectorPriorityQueue::size() {
	return vect.size();
}

bool VectorPriorityQueue::isEmpty() {
	return vect.isEmpty();
}

void VectorPriorityQueue::enqueue(string value) {
	vect.add(value);
}

string VectorPriorityQueue::peek() {
	if (vect.isEmpty()) {
		error("ERROR");
	}
	string result = vect[0];
	for (int i = 0; i < vect.size(); i++){
		if (vect[i] < result){
			result = vect[i];
		}
	}
	return result;
}

string VectorPriorityQueue::dequeueMin() {
	if (vect.isEmpty()) {
		error("ERROR");
	}
	string result = vect[0];
	int index = 0;
	for (int i = 0; i < vect.size(); i++){
		if (vect[i] < result){
			result = vect[i];
			index = i;
		}
	}
	vect.remove(index);
	return result;
}

