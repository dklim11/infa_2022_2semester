#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void detect() {
	int left = 0, right = 359;
	if (get_results(358) > get_results(359)) {
		
	}
}

uint32_t get_results(uint32_t channel) {
    static uint32_t calls = 0;
    calls++;
    if (calls > 25) return static_cast<uint32_t>(-1);

    static uint32_t min = 10, max = 255760;
    static uint32_t min_channel = 50, max_channel = 250;
    static uint32_t zero = 100000;

    if (channel <= min_channel)
        return static_cast<uint32_t>(zero - channel*((double)zero - min)/min_channel);
    if (channel <= max_channel)
        return static_cast<uint32_t>(min + ((double)channel - min_channel)*((double)max - min)/((double)max_channel - min_channel));
    if (channel <= 360)
        return static_cast<uint32_t>(max - ((double)channel - max_channel)*((double)max - zero)/((double)360 - max_channel));
    return static_cast<uint32_t>(-1);
}
int main() {
    detect();
    return 0;
}
