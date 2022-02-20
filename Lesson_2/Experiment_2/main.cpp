#include <iostream>
#include <random>
#include <chrono>

using namespace std;

/*
int random(int bound) {
	mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> dist(0, bound);
	
	return dist(rng);
}
*/

bool check(int (&array)[30][30], int i, int j) {
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

void move(int (&array)[30][30], int size) {
	int movement[size][size] = {0};
	int direction;
	mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> dist(0, 3);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array[i][j] == 1 && movement[i][j] == 0) {
				direction = dist(rng);
				if (direction == 0) {
					if (array[i - 1][j] == 0) {
						array[i - 1][j] = 1;
						movement[i - 1][j] = 1;
						array[i][j] = 0;
					}
				} else if (direction == 1) {
					if (array[i][j - 1] == 0) {
						array[i][j - 1] = 1;
						movement[i][j - 1] = 1;
						array[i][j] = 0;
					}
				} else if (direction == 2) {
					if (array[i + 1][j] == 0) {
						array[i + 1][j] = 1;
						movement[i + 1][j] = 1;
						array[i][j] = 0;
					}
				} else {
					if (array[i][j + 1] == 0) {
						array[i][j + 1] = 1;
						movement[i][j + 1] = 1;
						array[i][j] = 0;
					}
				}
			}
		}
	}
}

void step(int (&array)[30][30], int size, int &quantity) {
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

void print(int (&a)[30][30], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	const int size = 30;
	
	int array[size][size] = {0};
	int quantity = 0; 
	
	mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> dist(0, 1);
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			array[i][j] = dist(rng);
			if (array[i][j] == 1) {
				quantity++;
			}
		}
	}
	
	float Area = (float)quantity/(size*size);
	//print(array, size);
	int count = 0;
	while (quantity > 0) {
		step(array, size, quantity);
		count++;
		//cout << quantity << endl;
	}
	
	cout << count << " " << Area << endl;
	//print(array, size);
	return 0;
}
