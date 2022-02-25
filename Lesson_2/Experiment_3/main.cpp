#include <iostream>
#include <random>
#include <chrono>
#include <cmath>

using namespace std;

const int size = 10;

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist(0, size);

bool check(int (&array)[size], int i) {
	bool flag = false;
	if (array[i - 1] == 1 || array[i - 1] == 2) {
		flag = true;
	}
	if (array[i + 1] == 1 || array[i + 1] == 2) {
		flag = true;
	}
	
	return flag;
}

void move(int (&array)[size], int size) {
	int movement[size] = {0};
	int direction;

	for (int i = 0; i < size; i++) {
		if (array[i] == 1 && movement[i] == 0) {
			direction = dist(rng) % 2;
			if (direction == 0) {
				if (array[i - 1] == 0) {
					array[i - 1] = 1;
					movement[i - 1] = 1;
					array[i] = 0;
				}
			} else {
				if (array[i + 1] == 0) {
					array[i + 1] = 1;
					movement[i + 1] = 1;
					array[i] = 0;
				}
			}
		}
	}
}

void step(int (&array)[size], int size, int &quantity) {
	for (int i = 0; i < size; i++) {
		if (array[i] == 1 && (i == 0 || i == size - 1)) {
			array[i] = 2;
			quantity--;
		} else if (array[i] == 1) {
			if (check(array, i)) {
				array[i] = 2;
				quantity--;
 			}
		}
	}
	
	move(array, size);
}

void print(int (&a)[size], int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int quantity, count;
	double average = 0;
	
	for (int k = 1; k < 3000; k++) {
		int array[size] = {0};
		
		array[(size-1)/2] = 1;
		count = 0;
		quantity = 1;
		
		while (quantity > 0) {
			step(array, size, quantity);
			count++;
		}
		
		average = (average*(k - 1) + count)/k;
	}
	
	cout << "Average number of steps to the bound: " << average << endl;
	
	int quantity_st, coord;
	average = 0;
	//quantity_st is in percents
	cin >> quantity_st;
	
	quantity_st = size*quantity_st/100;
	double Area = (double)quantity_st/size;
		
	for (int k = 1; k < 3000; k++) {
		int	array[size] = {0};
		quantity = quantity_st; 
		
		while (quantity > 0) {
			coord = dist(rng) % size;
			if (array[coord] == 0) {
				quantity--;
				array[coord] = 1;
			}
		}
		
		quantity = quantity_st;
		count = 0;
		while (quantity > 0) {
			step(array, size, quantity);
			count++;
		}
		--count;
		
		average = (average * (k - 1) + count)/k;
	}
	
	cout << "Average number of steps till stop: " << average << endl;
	return 0;
}
