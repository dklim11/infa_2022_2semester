#include <iostream>
#include <random>
#include <chrono>

using namespace std;

bool check(int (&array)[40], int j) {
	bool flag = false;
	if (array[j - 1] == 1 || array[j - 1] == 2) {
		flag = true;
	}
	if (array[j + 1] == 1 || array[j + 1] == 2) {
		flag = true;
	}
	
	return flag;
}

void move(int (&array)[40], int size) {
	int movement[size] = {0};
	int direction;
	mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> dist(0, 1);
	
	for (int j = 0; j < size; j++) {
		if (array[j] == 1 && movement[j] == 0) {
			direction = dist(rng);
			if (direction == 0) {
				if (array[j - 1] == 0) {
					array[j - 1] = 1;
					movement[j - 1] = 1;
					array[j] = 0;
				}
			} else if (direction == 1) {
				if (array[j + 1] == 0) {
					array[j + 1] = 1;
					movement[j + 1] = 1;
					array[j] = 0;
				}
			}
		}
	}
}

void step(int (&array)[40], int size, int &quantity) {
	for (int j = 0; j < size; j++) {
		if (array[j] == 1 && (j == 0 || j == size - 1)) {
			array[j] = 2;
			quantity -= 1;
		} else if (array[j] == 1) {
			if (check(array, j)) {
				array[j] = 2;
				quantity -= 1;
			}
		}
	}
	
	move(array, size);
}

void print(int (&a)[40], int size) {
	for (int j = 0; j < size; j++) {
		cout << a[j] << " ";
	}
	cout << endl;
}

int main() {
	const int size = 40;
	
	int array[size] = {0};
	int quantity = 0; 
	
	mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> dist(0, 1);
	
	for (int j = 0; j < size; j++) {
		array[j] = dist(rng);
		if (array[j] == 1) {
			quantity++;
		}
	}
	
	double Area = (double)quantity/(size);
	print(array, size);
	int count = 0;
	while (quantity > 0) {
		//cout << quantity << endl;
		step(array, size, quantity);
		count++;
	}
	
	cout << count << " " << Area << endl;
	print(array, size);
	return 0;
}
