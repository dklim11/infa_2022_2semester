#include <iostream>

using namespace std;

struct Node{
	int val;
	Node *next;
};

struct List{
	int size;
	Node *head;
	Node *tail;
};

int getCycle(Node *head) {
	
}

int main() {
	int n;
	cin >> n;
	
	List *list = new List;
	Node *tmp = new Node;
	int a;
	cin >> a;
	tmp->val = a;
	list->size = 1;
	list->head = tmp;
	list->tail = tmp;
	tmp->next = nullptr;
	
	for (int i = 1; i < n; i++){
		Node *tmp = new Node;
		cin >> a;
		tmp->val = a;
		tmp->next = nullptr;
		list->tail = tmp;
	}
	
	cout << getCycle(list->head) << endl;
	return 0;
}
