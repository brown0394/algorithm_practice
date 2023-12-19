#include <iostream>
#include <vector>
#include <stack>

int main() {
	char str[101];
	scanf_s("%s", &str, 101);
	std::stack<char> opstk;
	for (int i = 0; str[i] > 0; ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			printf("%c", str[i]);
		}
		else {
			switch (str[i]) {
				case '+' :
				case '-': {
					while (!opstk.empty() && opstk.top() != '(') {
						printf("%c", opstk.top());
						opstk.pop();
					}
					opstk.push(str[i]);
					break;
				}
				case '*' :
				case '/': {
					while (!opstk.empty() && (opstk.top() == '*' || opstk.top() == '/')) {
						printf("%c", opstk.top());
						opstk.pop();
					}
					opstk.push(str[i]);
					break;
				}
				case '(': { opstk.push(str[i]); break; }
				case ')': {
					while (!opstk.empty() && opstk.top() != '(') {
						printf("%c", opstk.top());
						opstk.pop();
					}
					opstk.pop();
					break;
				}
			}
			
		}
	}
	while (!opstk.empty()) {
		printf("%c", opstk.top());
		opstk.pop();
	}
	putchar('\n');
}