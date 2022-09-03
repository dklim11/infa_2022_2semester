#include <iostream>

using namespace std;

struct Node{
	int val;
	Node *next;
};

struct Queue{
	unsigned size = 0;
	Node *head = nullptr;
	Node *tail = nullptr;
};

void clear(Queue *queue) {
	Node *tmp = queue->head;
	
	while(tmp != nullptr) {
		queue->head = tmp->next;
		delete tmp;
		tmp = queue->head;
	}
	queue->tail = nullptr;
	queue->size = 0;
}

void enQueue(Queue *queue, int new_val) {
	Node *tmp = new Node;
	tmp->val = new_val;
	
	if (queue->size == 0) {
		queue->head = tmp;
		queue->tail = tmp;
	} else {
		queue->tail->next = tmp;
		queue->tail = tmp;	
	}
	
	queue->tail->next = nullptr;
	queue->size++;
}

int deQueue(Queue *queue) {
	int a;
	if (queue->head == nullptr) {
		a = -100000;
		cout << "-100000 returned as queue is empty ";
	} else if (queue->size == 1) {
		a = queue->head->val;
		clear(queue);
	} else {
		Node *ptr = queue->head;
		a = ptr->val;
		queue->head = ptr->next;
		delete ptr;
		queue->size--;
	}
	return a;
}

int front(Queue *queue) {
	int a;
	if (queue->head == nullptr) {
		a = -100000;
		cout << "-100000 returned as queue is empty";
	} else {
		a = queue->head->val;
	}
	return a;
}

int rear(Queue *queue) {
	int a;
	if (queue->tail == nullptr) {
		a = -100000;
		cout << "-100000 returned as queue is empty";
	} else {
		a = queue->tail->val;
	}
	return a;
}

unsigned length(Queue *queue) {
	return queue->size;
}

void print(Queue *queue) {
	if (queue->size == 0) {
		cout << "Queue is empty";
	} else {
		Node *tmp = queue->head;
		while(tmp != nullptr) {
			cout << tmp->val << " ";
			tmp = tmp->next;
		}
	}
	cout << endl;
}

int main() {
	unsigned n;
	cin >> n;
	
	Queue *queue = new Queue;
	
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		enQueue(queue, tmp);
	}
	
	for (int i = 0; i < n; i++) {
		cout << deQueue(queue) << endl;
	}
	cout << deQueue(queue) << endl;
	print(queue);
	return 0;
}
