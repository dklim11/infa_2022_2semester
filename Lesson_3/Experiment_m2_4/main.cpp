#include <iostream>
#include <random>
#include <chrono>
#include <cmath>

using namespace std;

const int size = 101;

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

void move_1(int (&array)[size][size], int size, int &possibility) {
	int chance = dist(rng) % 100;
	
	int movement[size][size] = {0};
	int direction;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array[i][j] == 1 && movement[i][j] == 0) {
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

void move_2(int (&array)[size][size], int size, int &possibility) {
	int chance = dist(rng) % 100;
	
	int movement[size][size] = {0};
	int direction;
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array[i][j] == 1 && movement[i][j] == 0) {
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

void step_1(int (&array)[size][size], int size, int &quantity, int &possibility) {
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
	
	move_1(array, size, possibility);
}

void step_2(int (&array)[size][size], int size, int &quantity, int &possibility) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array[i][j] == 1 && (i == 0 || i == size - 1 || j == 0 || j == size - 1)) {
				array[i][j] = 2;
				quantity--;
			}
		}
	}
	
	move_2(array, size, possibility);
}

void print(int (&a)[size][size], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int insertion(int array[size][size], int quantity_st) {
	int quantity, coord1, coord2;
	quantity = quantity_st
	
	while (quantity > 0) {
		coord1 = dist(rng) % size;
		coord2 = dist(rng) % size;
		if (array[coord1][coord2] == 0) {
			quantity--;
			array[coord1][coord2] = 1;
		}
	}
	
	return array;
}

int main() {
	int quantity_st_1, quantity_st_2, coord1, coord2, possibility;
	double average = 0;
	//quantity_st is in percents
	cout << "Input a percent of first-type dislocations in cristall: " << endl;
	cin >> quantity_st_1;
	cout << endl;
	
	cout << "Input a percent of second-type dislocations in cristall: " << endl;
	cin >> quantity_st_2;
	cout << endl;
	
	cout << "Input a possibility of first-type dislocation's freezing from 1 to 100: " << endl;
	cin >> possibility_1;
	cout << endl;
	
	cout << "Input a possibility of second-type dislocation's freezing from 1 to 100: " << endl;
	cin >> possibility_2;
	cout << endl;
	
	quantity_st = (size*size)*quantity_st/100;
	double Area = (double)quantity_st/(size*size);
	
	//array_1 has a behaviour which is similar to previous model of dislocations.
	//array_2 represents a new_type dislocations
	int quantity_1, quantity_2;	
	for (int k = 1; k < 2000; k++) {
		int	array_1[size][size] = {0};
		int array_2[size][size] = {0};
		
		array_1 = insertion(array_1, quantity_st_1);
		array_2 = insertion(array_2, quantity_st_2);
		
		quantity = quantity_st;
		
		int count = 0;
		while (quantity_1 > 0 || quantity_2 > 0) {
			if (quantity_1 > 0) {
				step(array_1, size, quantity_1, possibility_1);
			}
			if (quantity_2 > 0) {
				step(array_2, size, quantity_2, possibility_2);	
			}
			count++;
		}
		--count;
		
		average = (average * (k - 1) + count)/k;
	}
	
	cout << average << endl;
	return 0;
}
