#include <iostream>
#include <string>


int main() {
	int len, swapLen;
	std::cin >> len >> swapLen;
	char str[500005];
	scanf_s("%s", str, 500005);
	--swapLen;
	for (int i = swapLen; i < len; ++i) {
		printf("%c", str[i]);
	}
	bool reverseOrder = true;
	if (!(swapLen % 2)) reverseOrder = !reverseOrder;
	if (len % 2) reverseOrder = !reverseOrder;
	if (reverseOrder) {
		for (int i = swapLen-1; i >= 0; --i) {
			printf("%c", str[i]);
		}
	}
	else {
		for (int i = 0; i < swapLen; ++i) {
			printf("%c", str[i]);
		}
	}
	printf("\n");
}