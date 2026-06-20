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