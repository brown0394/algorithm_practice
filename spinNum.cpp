#include <iostream>
#include <vector>

void getDiff(char one, char two, int* diffLeft, int* diffRight) {
	if (one > two) {
		*diffLeft = two + 10 - one;
		*diffRight = one - two;
	}
	else if (one < two) {
		*diffLeft = one - two;
		*diffRight = two + 10 - one;
	}
	else {
		*diffLeft = 0;
		*diffRight = 0;
	}
}

int main() {
	int stacked;
	char start[6];
	char target[6];
	
	scanf_s("%d %c", &stacked);
	scanf_s("%s\n%s", start, target);
	std::vector<int> spin(stacked + 1);
	int lastDiffLeft, lastDiffRight;
	getDiff(start[0], target[0], &lastDiffLeft, &lastDiffRight);
	int left = 0;
	int curDiffLeft, curDiffRight;
	char l, r;
	for (int i = 1; i < stacked; ++i) {

	}
	
}
