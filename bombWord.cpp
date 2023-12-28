#include <iostream>
#include <cstring>
#include <stack>


struct node {
	int start;
	int end;
};

int main() {
	char str[1000001];
	char bomb[37];
	scanf_s("%s %s", str, 1000001, bomb, 37);
	std::stack<node> stk;
	int bombLen = strlen(bomb);
	int strLen = strlen(str);
	int newIdx = 0;
	for (int i = 0; i < strLen; ++i) {
		if (str[i] == bomb[0] && i + bombLen <= strLen) {
			int idx = 0;
			for (; idx < bombLen; ++idx) {
				if (str[i + idx] != bomb[idx]) break;
				else str[newIdx++] = str[i + idx];
			}///
			if (idx == bombLen) {
				newIdx -= bombLen;
				while (!stk.empty() && stk.top().end == newIdx) {
					int base = stk.top().end - stk.top().start;
					stk.pop();
					if (i + (bombLen - base) <= strLen) {
						int j = base;
						for (; j < bombLen; ++j) {
							if (str[i] != bomb[j]) break;
							else str[newIdx++] = str[i];
							++i;
						}
						if (j == bombLen) newIdx -= bombLen;
					}
				}
				--i;
			}
			else {
				stk.push({ newIdx - idx, newIdx });
				--i;
			}
		}
		else {
			str[newIdx++] = str[i];
		}
	}
	if (newIdx) {
		str[newIdx] = '\0';
		printf("%s\n", str);
	}
	else printf("FRULA\n");
}