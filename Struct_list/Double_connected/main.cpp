#include <iostream>

using namespace std;

struct Node{
	int val;
	Node *next;
	Node *prev;
};

struct DoubleList{
	int size = 0;
	Node *head = nullptr;
	Node *tail = nullptr;
};

void push_back(DoubleList *list, int new_val) {
	Node *tmp = new Node;
	tmp->val = new_val;
	
	if (list->size == 0) {
		list->head = tmp;
		list->tail = tmp;
		tmp->prev = nullptr;
	} else {
		tmp->prev = list->tail;
		list->tail->next = tmp;
		list->tail = tmp;
	}
	list->tail->next = nullptr;	
	list->size++;
}

void push_front(DoubleList *list, int new_val) {
	Node *tmp = new Node;
	tmp->val = new_val;
	
	if (list->size == 0) {
		list->head = tmp;
		list->tail = tmp;
		tmp->next = nullptr;
	} else {
		list->head->prev = tmp;
		tmp->next = list->head;
		list->head = tmp;
	}
	list->head->prev = nullptr;
	list->size++;
}

void insert(DoubleList *list, int idx, int new_val) {
	Node *tmp = new Node;
	tmp->val = new_val;
	
	if (idx == 0) {
		push_front(list, new_val);
	} else if (idx < list->size || idx > 0) {
		Node *ptr = list->head;
		for (int i = 0; i < idx - 1; i++) {
			ptr = ptr->next;
		}
		
		tmp->prev = ptr;
		tmp->next = ptr->next;
		ptr->next->prev = tmp;
		ptr->next = tmp;
		list->size++;
	} else if (idx == list->size) {
		push_back(list, new_val);
	} else {
		cout << "Argument idx is out of bounds" << endl;
	}
}

void pop_back(DoubleList *list) {
	if (list->size <= 1) {
		list->head = nullptr;
		list->tail = nullptr;
		list->size = 0;
	} else {
		list->tail = list->tail->prev;
		delete list->tail->next;
		list->tail->next = nullptr;
		list->size--;	
	}
}

void pop_front(DoubleList *list) {
	if (list->size <= 1) {
		list->head = nullptr;
		list->tail = nullptr;
		list->size = 0;
	} else {
		list->head = list->head->next;
		delete list->head->prev;
		list->head->prev = nullptr;
		list->size--;	
	}
}

void remove(DoubleList *list, int idx) {
	if (idx == 0) {
		pop_front(list);
	} else if (idx >= list->size || idx < 0) {
		cout << "Argument idx is out of bounds" << endl;
	} else if (idx == list->size - 1) {
		pop_back(list);
	} else {
		Node *ptr = list->head;
		
		for (int i = 0; i < idx - 1; i++) {
			ptr = ptr->next;
		}
		
		ptr->next = ptr->next->next;
		ptr->next->prev = ptr;	
		list->size--;
	}
}

int length(DoubleList *list) {
	return list->size;
}

int get(DoubleList *list, int idx) {
	Node *ptr = list->head;
	
	int a;
	if (idx < 0 || idx >= list->size) {
		a = -1;
	} else {
		for (int i = 0; i < idx; i++) {
			ptr = ptr->next;
		}
		a = ptr->val;
	}
	return a;
}

void clear(DoubleList *list) {
	Node *ptr = list->head;
	Node *tmp;
	
	while (ptr != nullptr) {
		tmp = ptr->next;
		delete ptr;
		ptr = tmp;
	}
	
	list->head = nullptr;
	list->tail = nullptr;
	list->size = 0;
}

void printReverse(DoubleList *list) {
	if (list->size == 0) {
		cout << "List is empty";
	} else {
		Node *ptr = list->tail;
		while (ptr != nullptr) {
			cout << ptr->val << " ";
			ptr = ptr->prev;
		}
	}
	cout << endl;
}

void print(DoubleList *list) {
	Node *tmp = list->head;
	while(tmp != nullptr) {
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
}

int main() {
	int n;
	cin >> n;
	
	DoubleList *list = new DoubleList;
	
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		push_back(list, tmp);
	}
	print(list);
	clear(list);
	return 0;
}
