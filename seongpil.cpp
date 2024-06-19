#include <iostream>
#include <stack>

int main() {
	std::string input;
	std::cin >> input;
	std::stack<int> stk;
	for (int i = 0, size = input.size(); i < size; ++i) {
		if (input[i] >= '0' && input[i] <= '9') {
			stk.push(input[i] - '0');
		}
		else {
			int one, two;
			two = stk.top();
			stk.pop();
			one = stk.top();
			stk.pop();
			switch (input[i]) {
			case '+': { stk.push(one + two); break; }
			case '-': { stk.push(one - two); break; }
			case '*': { stk.push(one * two); break; }
			case '/': { stk.push(one / two); break; }
			}
		}
	}
	printf("%d\n", stk.top());
}