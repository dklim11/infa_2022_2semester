#include <iostream>
#include <cmath>

using namespace std;

struct Node{
	int val;
	Node *next;
};

struct List{
	unsigned size = 0;
	Node *head = nullptr;
	Node *tail = nullptr;
};

void push_back(List *list, int new_val) {
	Node *tmp = new Node;
	tmp->val = new_val;
	
	if (list->size == 0) {
		list->head = tmp;
		list->tail = tmp;
		list->tail->next = nullptr;
	} else {
		list->tail->next = tmp;
		list->tail = tmp;
		list->tail->next = nullptr;	
	}
	list->size++;
}

void push_front(List *list, int new_val) {
	Node *tmp = new Node;
	tmp->val = new_val;
	
	if (list->size > 0) {
		tmp->next = list->head;
		list->head = tmp;
	} else {
		list->head = tmp;
		list->tail = tmp;
		list->tail->next = nullptr;
	}
	
	list->size++;
}

Node* get_elem(List *list, int idx) {
	if (idx < 0 || idx >= list->size) {
		return nullptr;
	}
	Node *pointer = list->head; 
	for (int i = 0; i < idx - 1; i++) {
		pointer = pointer->next;
	}
	
	return pointer;
}

void insert(List *list, int new_val, int idx){
	if (idx < 0 || idx > list->size) {
		cout << "Argumet idx is out of range" << endl;
	} else if (idx == list->size) {
		push_back(list, new_val);
	} else if (idx == 0) {
		push_front(list, new_val);
	} else {
		Node *tmp = new Node;
		tmp->val = new_val;
		
		if (idx == 1) {
			tmp->next = list->head->next;
			list->head->next = tmp;
		} else {
			Node *pointer = get_elem(list, idx); 
			tmp->next = pointer->next;
			pointer->next = tmp;
		}
		list->size++;
	}
}

void pop_back(List *list) {
	if (list->size <= 1) {
		list->head = nullptr;
		list->tail = nullptr;
		list->size = 0;
	} else {
		Node *pointer = list->head;
		for (int i = 0; i < list->size - 2; i++) {
			pointer = pointer->next;
		}
		
		delete list->tail;
		
		list->tail = pointer;
		pointer->next = nullptr;
		list->size--;	
	}
}

void pop_front(List *list) {
	if (list->size <= 1) {
		list->head = nullptr;
		list->tail = nullptr;
		list->size = 0;
	} else {
		Node *pointer = list->head;
	
		list->head = list->head->next;
		delete pointer;
		list->size--;
	}
}

void remove(List *list, int idx) {
	if (idx < 0 || idx >= list->size) {
		cout << "Ardument idx is out of range" << endl;
	} else if (list->size <= 1) {
		list->head = nullptr;
		list->tail = nullptr;
		list->size = 0;
	} else {
		Node *pointer = list->head;
	
		for (int i = 0; i < idx - 1; i++) {
			pointer = pointer->next;
		}
		Node *tmp = pointer->next;
		pointer->next = pointer->next->next;
		delete tmp;	
	}
}

int get(List *list, int idx) {
	int a;
	if (list->size == 0) {
		cout << "List is empty, -100000 returned" << endl;
		a = -100000;
	} else {
		Node *ptr = list->head;
	
		if (idx < 0 || idx >= list->size) {
			cout << "Argument idx is out of range" << endl;
			a = -100000;
		} else {
			for (int i = 0; i < idx; i++) {
				ptr = ptr->next;
			}
			a = ptr->val;
		}
	}
	
	return a;
}

unsigned length(List *list) {	
	return list->size;
}

void clear(List *list) {
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

void print(List *list) {
	if (list->size == 0) {
		cout << "List is empty";
	} else {
		Node *pointer = list->head;
	
		while(pointer != nullptr) {
			cout << pointer->val << " ";
			pointer = pointer->next; 
		}
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	
	List *list = new List;
	Node *tmp = new Node;
	
	print(list);
	push_back(list, 5);
	push_front(list, 10);
	push_back(list, 2);
	print(list);
	
	int tmpa;
	for(int i = 0; i < n; i++) {
		cin >> tmpa;
		push_back(list, tmpa);
	}	
	
	print(list);
	return 0;
}
