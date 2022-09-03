#include <iostream>
#include <cmath>

using namespace std;

struct Node{
	int val;
	Node *next;
};

struct List{
	unsigned size;
	Node *head;
	Node *tail;
};

void Reverse(Node **head) {
	Node *tmp1 = *head;
	Node *tmp2 = (*head)->next;
	
	tmp1->next = nullptr;

	while(tmp2->next != nullptr) {
		Node *tmp = tmp2->next;
		tmp2->next = tmp1;
		tmp1 = tmp2;
		tmp2 = tmp;
	}
	
	tmp2->next = tmp1;
	*head = tmp2;
}

int main() {
	int n;
	cin >> n;
	
	List *list = new List;
	Node *tmp = new Node;
	
	list->head = tmp;
	list->tail = tmp;
	list->size = n;
	tmp->val = 1;
	
	for (int i = 1; i < n; i++) {
		tmp = new Node;
		list->tail->next = tmp;
		list->tail = tmp;
		tmp->val = i + 1;
	}
	list->tail->next = nullptr;
	
	Reverse(&list->head);
	
	tmp = list->head;
	while(tmp->next != nullptr) {
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << tmp->val << endl;
	return 0;
}
