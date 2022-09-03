#include <iostream>

using namespace std;

struct Node{
	char val;
	Node *next;
};

struct Stack{
	unsigned size = 0;
	Node *head = nullptr;
};

void push(Stack *stack, char new_val) {
	Node *tmp = new Node;
	tmp->next = stack->head;
	stack->size++;
	tmp->val = new_val;
	stack->head = tmp;
}

int pop(Stack *stack) {
	char a;
	Node *tmp = stack->head;
	stack->head = tmp->next;
	stack->size--;
	a = tmp->val;
	
	delete tmp;
	return a;		
}

Node* top(Stack *stack) {
	return stack->head;
}

bool empty(Stack *stack) {
	bool flag = false;
	if (stack->size == 0) {
		flag = true;
	}
	
	return flag;
}

void clear(Stack *stack) {
	Node *ptr = stack->head;
	
	while(ptr != nullptr) {
		ptr = stack->head->next;
		delete stack->head;
		stack->head = ptr;
	}
	stack->size = 0;
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

bool check_val(Stack *stack) {
	bool flag = false;
	if (top(stack)->val == ')' || top(stack)->val == ']' || top(stack)->val == '}' || top(stack)->val == '>') {
		flag = true;
	}

	return flag;
}

bool same_type(Stack *stack) {
	bool flag = false;
	
	if (top(stack)->val == ')' && top(stack)->next->val == '(') {
		flag = true;
	}
	if (top(stack)->val == '}' && top(stack)->next->val == '{') {
		flag = true;	
	}
	if (top(stack)->val == ']' && top(stack)->next->val == '[') {
		flag = true;
	}
	if (top(stack)->val == '>' && top(stack)->next->val == '<') {
		flag = true;	
	}
	pop(stack);
	pop(stack);	
	
	return flag;
} 

bool check(Stack *stack) {
	bool flag = false;
	
	if (check_val(stack)) {
		if (stack->size == 1) {
			flag = true;
		} else {
			if (!same_type(stack)) {
				flag = true;
			}
		}
	}
	
	return flag;
}

bool if_num(char c) {
	bool flag = false;
	if (c >= '0' && c <= '9') {
		flag = true;
	}
	
	return flag;
}

int main() {
	const char *line = "5+10+1";
	int line_size = 6;
	
	char tmp;
	Stack *stack = new Stack;
	
	bool flag = true;
	for (int i = 0; i < line_size; i++) {
		tmp = line[i];
		if (tmp == '(' || tmp == ')' || tmp == '[' || tmp == ']' || tmp == '{' || tmp == '}' || tmp == '<' || tmp == '>') {
			push(stack, tmp);
			if (check(stack)) {
				flag = false;
				cout << "Incorrect input" << endl;
				break;
			}		
		}
	}
	
	if (stack->size > 0 && flag) {
		flag = false;
		cout << "Incorrect input" << endl;
	}
	if (flag) {
		clear(stack);
		
		char *post = new char [line_size*2];
		int count = 0;
		for (int i = 0; i < line_size; i++) {
			if (if_num(line[i])) {
				post[count] = line[i];
				count++;
			} else {
				post[count] = ' ';
				count++;
				push(stack, line[i]);
			}
		}
		
		while(stack->size > 0) {
			post[count] = pop(stack);
			count++;
		}
		
		for (int i = 0; i < count; i++) {
			cout << post[i];
		}
		
		//We cross the line; if number, push to stack; otherwise, 
		//count the result of operator, applied to top 2 elements in stack 
		clear(stack);
		for (int i = 0; i < count; i++) {
		
		}
		
		delete []post;
	}
	return 0;
}
