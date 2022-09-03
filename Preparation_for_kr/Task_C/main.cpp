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

int main() {
	int n, k;
	cin >> n >> k;
	
	List *list = new List;
	Node *tmp = new Node;
	
	tmp->next = nullptr;
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
	list->tail->next = list->head;
	
	tmp = list->head;
	int count = 0;
	while(tmp->next != tmp) {
		if (count == k - 2) {
			tmp->next = tmp->next->next;
			tmp = tmp->next;
			count = 0;
		} else {
			tmp = tmp->next;
			count++;
		}
	}
	
	cout << tmp->val << endl;
	return 0;
}
