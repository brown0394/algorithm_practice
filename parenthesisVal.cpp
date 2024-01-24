#include <iostream>
#include <stack>

int calcParenth(char* str, int* idx, std::stack<char>& stk) {
	int sum = 0;
	for (; str[*idx] != '\0'; ++(*idx)) {
		switch (str[*idx]) {
		case '(': { }
		case '[': {
			if (str[*idx] == '(') stk.push('(');
			else stk.push('[');
			++(*idx);
			int val = calcParenth(str, idx, stk);
			if (!val) return 0;
			sum += val;
			break;
		}
		case ')': {
			if (stk.empty()) return 0;
			if (stk.top() != '(') return 0;
			else {
				stk.pop();
				if (!sum) return 2;
				else return sum << 1;
			}
		}
		case ']':
			if (stk.empty()) return 0;
			if (stk.top() != '[') return 0;
			else {
				stk.pop();
				if (!sum) return 3;
				else return sum * 3;
			}
		}
	}
	if (!stk.empty()) return 0;
	return sum;
}

int main() {
	char str[40];
	scanf_s("%s", str, 40);
	int idx = 0;
	std::stack<char> stk;
	printf("%d\n", calcParenth(str, &idx, stk));

}
