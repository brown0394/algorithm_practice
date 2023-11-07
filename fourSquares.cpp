#include <iostream>
#include <vector>

int main() {
	int N;
	scanf_s("%d", &N);
	std::vector<int> squares(224, 0);
	int idx = 224;
	for (int i = 1; i <= 224; ++i) {
		squares[i - 1] = i * i;
		if (squares[i - 1] > N) {
			idx = i - 2;
			break;
		}
	}
	std::vector<int> arr(N+1, 0);
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	int last = 1;
	int cur, min;
	for (int i = 4; i <= N; ++i) {
		if (squares[last + 1] <= i) {
			++last;
		}
		cur = last;
		min = arr[i - squares[cur]];
		while (cur > 0) {
			--cur;
			if (min > arr[i - squares[cur]]) {
				min = arr[i - squares[cur]];
			}
		}
		arr[i] =  min + 1;
	}
	printf("%d", arr[N]);
}