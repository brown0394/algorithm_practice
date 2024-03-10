#include <iostream>
#include <string>
#include <algorithm>

int main() {
	int n;
	scanf_s("%d", &n);
	std::string num = std::to_string(n);
	int len = num.size();
	std::string seq;
	for (int i = 1; i <= n; ++i) {
		seq.append(std::to_string(i));
	}
	for (int i = 0; i < seq.size(); ++i) {
		if (seq[i] == num[0]) {
			if (seq.compare(i, len, num) == 0) {
				printf("%d\n", i + 1);
				break;
			}
		}
	}
}
