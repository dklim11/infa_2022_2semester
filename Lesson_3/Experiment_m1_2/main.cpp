#include <iostream>
#include <random>
#include <chrono>
#include <cmath>

using namespace std;

const int size = 21;

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist(0, max(size, 100));

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

void move(int (&array)[size][size], int size, int &possibility) {
	int movement[size][size] = {0};
	int direction, chance;
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			chance = dist(rng) % 100;
			if (array[i][j] == 1 && movement[i][j] == 0 && chance >= possibility) {
				direction = dist(rng) % 4;
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

void step(int (&array)[size][size], int size, int &quantity, int &possibility) {
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
	
	move(array, size, possibility);
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
	int result[3000];
	int possibility;
	
	cout << "Input a possibility of dislocation's freezing from 1 to 100: " << endl;
	cin >> possibility;
	
	int j = 0, count;
	while (j < 3000) {
		int array[size][size] = {0};
		int quantity = 0; 
	
		array[size/2][size/2] = 1;	    
		quantity++;
		count = 0;
		while (quantity > 0) {
			step(array, size, quantity, possibility);
			count++;
			//cout << quantity << endl;
		}
		count--;
		result[j] = count;
		j++;
	}
	
	double sum = 0;
	for (int k = 0; k < 3000; k++) {
		sum += result[k];
	}
	
	cout << sum/3000 << endl;
	return 0;
}
