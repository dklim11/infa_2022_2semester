#include <iostream>
#include <random>
#include <chrono>
#include <cmath>

using namespace std;

const int size = 101;

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist(0, size);

bool check(int (&array)[size][size], int i, int j) {
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

void move(int (&array)[size][size], int size) {
	int movement[size][size] = {0};
	int direction;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array[i][j] == 1 && movement[i][j] == 0) {
				direction = dist(rng)%4;
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

void step(int (&array)[size][size], int size, int &quantity) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array[i][j] == 1 && (i == 0 || i == size - 1 || j == 0 || j == size - 1)) {
				array[i][j] = 2;
				quantity--;
			} else if (array[i][j] == 1) {
				if (check(array, i, j)) {
					array[i][j] = 2;
					quantity--;
 				}
			}
		}
	}
	
	move(array, size);
}

void print(int (&a)[size][size], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int quantity_st, coord1, coord2;
	double average = 0;
	//quantity_st is in percents
	cin >> quantity_st;
	
	quantity_st = (size*size)*quantity_st/100;
	double Area = (double)quantity_st/(size*size);
	
	int quantity;	
	for (int k = 1; k < 2000; k++) {
		int	array[size][size] = {0};
		quantity = quantity_st; 
		
		while (quantity > 0) {
			coord1 = dist(rng) % size;
			coord2 = dist(rng) % size;
			if (array[coord1][coord2] == 0) {
				quantity--;
				array[coord1][coord2] = 1;
			}
		}
		
		quantity = quantity_st;
		int count = 0;
		while (quantity > 0) {
			step(array, size, quantity);
			count++;
		}
		--count;
		
		average = (average * (k - 1) + count)/k;
	}
	
	cout << average << endl;
	return 0;
}
