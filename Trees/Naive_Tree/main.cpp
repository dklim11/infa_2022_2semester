#include <iostream>

using namespace std;

struct Node{
	int key = 0;
	Node *left = nullptr;
	Node *right = nullptr;
	Node *parent = nullptr;
};

Node *search(Node *root, int key) {
	if (root->key == key) {
		return root;
	}
	if (root->key > key) {
		if (root->left == nullptr) {
			return nullptr;
		} else {
			root = root->left;
			return search(root, key);	
		}
	} else {
		if (root->right == nullptr) {
			return nullptr;
		} else {
			root = root->right;
			return search(root, key);
		}
	}
}

int max_find(Node *root) {
	if (root->right == nullptr) {
		return root->key;
	} else {
		root = root->right;
		return max_find(root);
	}
}

int min_find(Node *root) {
	if (root->left == nullptr) {
		return root->key;
	} else {
		root = root->left;
		return min_find(root);
	}
}

void insert(Node *root, Node *z) {
	if (root->key > z->key) {
		if (root->left != nullptr) {
			root = root->left;
			insert(root, z);
		} else {
			root->left = z;
			z->parent = root;
		}
	}
}

void remove(Node *root, Node *z) {
	
}

void clear(Node *root) {
	if (root != nullptr) {
		clear(root->right);
		clear(root->left);
		delete root;
	}
}

int main() {
	
	
	return 0;
}
