#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "queue.h"

void initQueue(Queue* q) {
	q->head = nullptr;
	q->tail = nullptr;
}

bool isEmpty(const Queue* q) {
	return q->head == nullptr;
}

void enqueue(Queue* q, const User& user) {
	QueueNode* newNode = new QueueNode();
	newNode->data = user;
	newNode->next = nullptr;

	if (isEmpty(q)) {
		q->head = newNode;
		q->tail = newNode;
	}
	else {
		q->tail->next = newNode;
		q->tail = newNode;
	}
}

User dequeue(Queue* q) {
	if (isEmpty(q)) {
		std::cerr << "Error: Attempted to dequeue from an empty queue" << std::endl;
		exit(EXIT_FAILURE);
	}

	QueueNode* temp = q->head;
	User userData = temp->data;

	q->head = q->head->next;

	if (q->head == nullptr) {
		q->tail = nullptr;
	}

	delete temp;
	return userData;
}