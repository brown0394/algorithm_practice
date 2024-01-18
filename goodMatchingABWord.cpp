#include <iostream>
#include <cstring>
#include <stack>

int main() {
	char in[100001];
	int words;
	scanf_s("%d", &words);
	int count = 0;
	std::stack<char> stk;
	for (int i = 0; i < words; ++i) {
		scanf_s("%s", in, 100001);
		int len = strlen(in);
		if (len % 2) continue;
		for (int j = 0; in[j] != '\0'; ++j) {
			if (stk.empty()) stk.push(in[j]);
			else {
				if (stk.top() == in[j]) stk.pop();
				else stk.push(in[j]);
			}
		}
		if (stk.empty()) ++count;
		else {
			while (!stk.empty()) stk.pop();
		}
	}
	printf("%d\n", count);
}
