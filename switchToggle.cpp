#include <iostream>
#include <bitset>
int main() {
	int switches;
	scanf_s("%d", &switches);
	std::bitset<101> switchArr;
	for (int i = 0; i < switches; ++i) {
		char in;
		getchar();
		scanf_s("%c", &in);
		if (in == '1') switchArr[i].flip();
	}
	int students;
	scanf_s("%d", &students);
	int num, gender;
	for (int i = 0; i < students; ++i) {
		scanf_s("%d %d", &gender, &num);
		if (gender == 1) {
			int cur = num;
			while (cur <= switches) {
				switchArr[cur - 1].flip();
				cur += num;
			}
		}
		else {
			--num;
			switchArr[num].flip();
			int left = num - 1;
			int right = num + 1;
			while (left >= 0 && right < switches) {
				if (switchArr[left] == switchArr[right]) {
					switchArr[left--].flip();
					switchArr[right++].flip();
				}
				else break;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < switches; ++i) {
		if (count++) printf(" ");
		if (switchArr[i]) printf("1");
		else printf("0");
		if (count == 20) {
			printf("\n");
			count = 0;
		}
	}
	printf("\n");
}
