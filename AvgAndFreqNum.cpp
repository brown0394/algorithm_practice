#include <iostream>
#include <map>

int main() {
	int in;
	int avg = 0;
	int freq = 0;
	int freqNum;
	std::map<int, int> count;
	for (int i = 0; i < 10; ++i) {
		scanf_s("%d", &in);
		avg += in;
		auto found = count.find(in);
		if (found == count.end()) {
			count.insert({ in, 1 });
			if (!freq) {
				++freq;
				freqNum = in;
			}
		}
		else {
			++found->second;
			if (found->second > freq) {
				freq = found->second;
				freqNum = in;
			}
		}
	}
	printf("%d\n%d\n", avg / 10, freqNum);
}
