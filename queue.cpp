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

std::string factionToString(Faction f) {
	switch (f) {
	case RED: return "Red";
	case BLUE: return "Blue";
	case GREEN: return "Green";
	default: return "Unknown";
	}
}

static std::string generateUsername() {
	const std::string chars = "absdefghijklmnopqrstuvwxyz0123456789";
	std::string username = "";
	for (int i = 0; i < 10; i++) {
		username += chars[rand() % chars.size()];
	}
	return username;
}

int addRandomUsers(Queue* q, int count) {
	if (q == nullptr) {
		std::cerr << "Error: Queue pointer is null" << std::endl;
		return 1;
	}
	if (count <= 0) {
		std::cerr << "Error: Count must be greater than 0" << std::endl;
		return 2;
	}

	for (int i = 0; i < count; i++) {
		User newUser;
		newUser.username = generateUsername();
		newUser.level = (rand() % 60) + 1;
		newUser.faction = static_cast<Faction>(rand() % 3);

		enqueue(q, newUser);
	}
	return 0;
}

//Main Testing

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <number_of_users>" << std::endl;
		return EXIT_FAILURE;
	}

	int numUsers = atoi(argv[1]);
	if (numUsers <= 0) {
		std::cerr << "Error: Please give a positive integer for the number of users" << std::endl;
		return EXIT_FAILURE;
	}

	srand(static_cast<unsigned int>(time(nullptr)));
	Queue q;
	initQueue(&q);

	int result = addRandomUsers(&q, numUsers);
	if (result != 0) {
		std::cerr << "Error: addRandomUsers failed with code" << result << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "Successfully added" << numUsers << "users to the queue.\n";
	std::cout << "-------------------------------------------------------\n";

	int position = 1;
	while (!isEmpty(&q)) {
		User u = dequeue(&q);
		std::cout << "User #" << position++ << "\n";
		std::cout << "Username: " << u.username << "\n";
		std::cout << "Level: " << u.level << "\n";
		std::cout << "Faction: " << factionToString(u.faction) << "\n";
		std::cout << "---------------------------------------------\n";
	}
	std::cout << "Queue is now empty.\n";
	return EXIT_SUCCESS;
}