#ifndef QUEUE_H
#define QUEUE_H

#include <string>

enum Faction {
	RED,
	BLUE,
	GREEN
};

struct User {
	std::string username;
	int level;
	Faction faction;
};

struct QueueNode {
	User data;
	QueueNode* next;
};

struct Queue {
	QueueNode* head;
	QueueNode* tail;
};

void initQueue(Queue* q);
bool isEmpty(const Queue* q);
void enqueue(Queue* q, const User& user);
User dequeue(Queue* q);

#endif