#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int random(int bound) {
	mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> dist(0, bound);
	
	return dist(rng);
}

bool check(int (&array)[5][5], int i, int j) {
	bool flag = false;
	if (array[i - 1][j] == 1 || array[i - 1][j] == 2) {
		flag = true;
	}
	if (array[i + 1][j] == 1 || array[i + 1][j] == 2) {
		flag = true;
	}
	if (array[i][j - 1] == 1 || array[i][j - 1] == 2) {
		flag = true;
	} 
	if (array[i][j + 1] == 1 || array[i][j + 1] == 2) {
		flag = true;
	}
	
	return flag;
}

void move(int (&array)[5][5], int size) {
	int direction;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array[i][j] == 1) {
				direction = random(4);
				if (direction == 0) {
					if (array[i - 1][j] == 0) {
						array[i - 1][j] = 1;
						array[i][j] = 0;
					}
				} else if (direction == 1) {
					if (array[i][j - 1] == 0) {
						array[i][j - 1] = 1;
						array[i][j] = 0;
					}
				} else if (direction == 2) {
					if (array[i + 1][j] == 0) {
						array[i + 1][j] = 1;
						array[i][j] = 0;
					}
				} else {
					if (array[i][j + 1] == 0) {
						array[i][j + 1] = 1;
						array[i][j] = 0;
					}
				}
			}
		}
	}
}

void step(int (&array)[5][5], int size, int &quantity) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array[i][j] == 1 && (i == 0 || i == size - 1 || j == 0 || j == size - 1)) {
				array[i][j] = 2;
				quantity -= 1;
			} else if (array[i][j] == 1) {
				if (check(array, i, j)) {
					array[i][j] = 2;
					quantity -= 1;
 				}
			}
		}
	}
	
	move(array, size);
}

int main() {
	const int size = 5;
	
	int array[size][size];
	int quantity = 0; 
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			array[i][j] = random(2);
			if (array[i][j] == 1) {
				quantity++;
			}
		}
	}	    
	
	int count = 0;
	while (quantity > 0) {
		step(array, size, quantity);
		count++;
		cout << quantity << endl;
	}
	return 0;
}
