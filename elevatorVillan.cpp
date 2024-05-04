#include <iostream>
#include <vector>

int highest[6];
int curFlr[6];
std::vector<std::vector<int>> numLED{
	{0, 4, 3, 3, 4, 3, 2, 3, 1, 2},
	{4, 0, 5, 3, 2, 5, 6, 1, 5, 4},
	{3, 5, 0, 2, 5, 4, 4, 4, 2, 3},
	{3, 3, 2, 0, 3, 2, 3, 2, 2, 1},
	{4, 2, 5, 3, 0, 3, 4, 3, 3, 2},
	{3, 5, 4, 2, 3, 0, 1, 4, 2, 1},
	{2, 6, 4, 3, 4, 1, 0, 5, 1, 2},
	{3, 1, 4, 2, 3, 4, 5, 0, 4, 3},
	{1, 5, 2, 2, 3, 2, 1, 4, 0, 1},
	{2, 4, 3, 1, 2, 1, 2, 3, 1, 0}
};
int topFloor, kdigits, maxChange, curFloor;

int possibleNumbers(int idx, int till, int sum) {
	if (idx == kdigits && sum) return 1;
	for (int i = 0; i <= till; ++i) {
		//if (sum + numLED[highest[]][])
		//possibleNumbers(idx + 1, 9, numLED[][])
	}
}

void numToArr(int val, int* arr) {
	int idx = 0;
	int num = 1000000;
	while (!(val / num)) { num /= 10; }
	while (num) {
		arr[idx++] = val / num;
		val = val % num;
		num /= 10;
	}
	kdigits = idx - 1;
}

void numToArrFromBack(int val, int* arr, int size) {
	while (val) {
		arr[size--] = val % 10;
		val /= 10;
	}
}

int main() {
	scanf_s("%d %d %d %d", &topFloor, &kdigits, &maxChange, &curFloor);
	
	numToArr(topFloor, highest);
	numToArrFromBack(curFloor, curFlr, kdigits);
	int a = 10;
}