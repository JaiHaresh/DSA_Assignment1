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
