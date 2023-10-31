#include <iostream>
#include <vector>

int main() {
	int n, len;
	scanf_s("%d", &n);
	scanf_s("%d", &len);
	char* arr = new char[len+1];
	scanf_s("%s", arr);
	int iois = 0;
	char check[2]{ 'O', 'I'};
	n = 3 + ((n - 1) << 1) - 2;
	int till, checkIdx, checkI, checkedTill = 0;
	for (int i = 0; i < len; ++i) {
		if (arr[i] == 'I' && i < len - n - 1) {
			++i;
			till = i + n;
			checkIdx = 1;
			checkI = i;
			if (i < checkedTill) i = checkedTill + 1;
			for (; i < till; ++i) {
				checkIdx = (checkIdx + 1) % 2;
				if (arr[i] != check[checkIdx]) break;
			}
			if (arr[i] == 'I') {
				if (i == till) {
					++iois;
					i = checkI;
					checkedTill = till;
				}
				else {
					--i;
				}
			}
		}
	}
	printf("%d\n", iois);

	delete[] arr;
}