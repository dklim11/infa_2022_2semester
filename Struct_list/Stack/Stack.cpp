#include <iostream>

using namespace std;

struct Node{
	unsigned val;
	Node *next;
};

struct Stack{
	unsigned size = 0;
	Node *head = nullptr;
};

bool empty(Stack *);

void push(Stack *stack, int new_val) {
	Node *tmp = new Node;
	tmp->next = stack->head;
	stack->size++;
	tmp->val = new_val;
	stack->head = tmp;
}

int pop(Stack *stack) {
	int a;
	if (empty(stack)) {
		cout << "Stack is empty, -100000 returned" << endl;
		a = -100000;
	} else {
		Node *tmp = stack->head;
		stack->head = tmp->next;
		stack->size--;
		a = tmp->val;
		
		delete tmp;
	}
	
	return a;		
}

int top(Stack *stack) {
	int tmp;
	if (stack->size == 0) {
		tmp = -100000;
		cout << "Stack is empty, can not get the top" << endl;
	} else {
		tmp = stack->head->val;
	}
	return tmp;
}

bool empty(Stack *stack) {
	return stack->size == 0;
}

void clear(Stack *stack) {
	Node *ptr = stack->head;
	
	while(ptr != nullptr) {
		ptr = stack->head->next;
		delete stack->head;
		stack->head = ptr;
	}
	stack->size = 0;
	stack->head = nullptr;
}

void print(Stack *stack) {
	if (stack->size == 0) {
		cout << "Stack is empty";
	} else {
		Node *ptr = stack->head;
	
		while(ptr != nullptr) {
			cout << ptr->val << " ";
			ptr = ptr->next;
		}
	}
	cout << endl;
}

int main() {
	unsigned n;
	cin >> n;
	
	Stack *stack = new Stack;
	
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		push(stack, tmp);
	}
	pop(stack);
	print(stack);
	return 0;
}
