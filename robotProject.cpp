#include <iostream>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int lenToBlock;
	int blockArr[1000001];
	while (std::cin >> lenToBlock) {
		lenToBlock *= 10000000;
		int blocks;
		std::cin >> blocks;
		for (int i = 0; i < blocks; ++i) {
			std::cin >> blockArr[i];
		}
		std::sort(blockArr, blockArr + blocks);
		int start = 0, end = blocks - 1;
		while (start < end) {
			if (blockArr[start] + blockArr[end] == lenToBlock) {
				std::cout << "yes " << blockArr[start] << " " << blockArr[end] << "\n";
				break;
			}
			if (blockArr[start] + blockArr[end] > lenToBlock) {
				--end;
			}
			else ++start;
		}
		if (start >= end) std::cout << "danger\n";
	}
}