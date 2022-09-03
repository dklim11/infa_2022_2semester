#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const unsigned int N = 4;
const int left[N]  = {6, 3, 2, 3}; // command code 1
const int right[N] = {1, 2, 3, 4}; // command code 2
const int back[N]  = {1, 1, 1, 1}; // command code 3
const int meow[N]  = {3, 2, 3, 2}; // command code 4

void check_left(bool *flag, int* data_start, int* data_end, int* command, int** frame) {
	int *c;
	c = data_start;
	int count = 0;
	bool signal = true;
	while(c != data_end) {
		if (*c != left[count]) {
			signal = false;
		}
		count++;
		c++;
	}
	
	if (signal && !*flag) {
		*command = 1;
		*frame = data_start;
		*flag = true;
	}
}

void check_right(bool *flag, int* data_start, int* data_end, int* command, int** frame) {
	int count = 0;
	int *c;
	c = data_start;
	bool signal = true;
	while(c != data_end) {
		if (right[count] != *c) {
			signal = false;
		}
		count++;
		c++;
	}
	
	if (signal && !*flag) {
		*command = 2;
		*frame = data_start;
		*flag = true;
	}
}

void check_back(bool *flag, int* data_start, int* data_end, int* command, int** frame) {
	int count = 0;
	int *c;
	c = data_start;
	bool signal = true;
	while(c != data_end) {
		if (back[count] != *c) {
			signal = false;
		}
		count++;
		c++;
	}
	
	if (signal && !*flag) {
		*command = 3;
		*frame = data_start;
		*flag = true;
	}
}

void check_meow(bool *flag, int* data_start, int* data_end, int* command, int** frame) {
	int count = 0;
	int *c;
	c = data_start;
	bool signal = true;
	while(c != data_end) {
		if (meow[count] != *c) {
			signal = false;
		}
		count++;
		c++;
	}
	
	if (signal && !*flag) {
		*command = 4;
		*frame = data_start;
		*flag = true;
	}
}

void recognize(int* data_start, int* data_end, int* command, int** frame) {
	bool *flag = new bool;
	*flag = false;
	if (data_end - data_start >= N) {
		while(data_start + N - 1 != data_end) {
			check_left(flag, data_start, data_start + N, command, frame);
			check_right(flag, data_start, data_start + N, command, frame);
			check_back(flag, data_start, data_start + N, command, frame);
			check_meow(flag, data_start, data_start + N, command, frame);
			data_start++;
		}
	}
	
	if (!*flag) {
		*command = 0;
	}
	delete flag;
}

int main() {
    const int L = 7;
    int mindstream[L] = {1, 0, 6, 3, 2, 3, 2};
    int command = -1;
    int* frame = mindstream;
    int* end = mindstream + L;
    while (command) {
        recognize(frame, end, &command, &frame);
        if (!command) break;
        switch(command)
        {
            case 1:
                cout << "left ";
                break;
            case 2:
                cout << "right ";
                break;
            case 3:
                cout << "back ";
                break;
            case 4:
                cout << "MEOOOOW ";
                break;
        }
        frame += N;
    }
    cout << endl;
    return 0;
}
