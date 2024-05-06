#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> arr;


int calcVal(std::string& str) {
	int result = 0;
	char op = 0;
	int val = 0;
	for (int i = 0, end = str.size(); i < end; ++i) {
		switch (str[i]) {
		case '+': 
		case '-': {
			if (!op) {
				result = val;
			}
			else {
				if (op == '+') result += val;
				else result -= val;
			}
			op = str[i];
			break;
		}
		case ' ': { val = (val * 10) + (str[++i] - '0'); break; }
		default: { val = str[i] - '0'; }
		}
	}
	if (!op) return 1;
	else if (op == '+') result += val;
	else result -= val;
	return result;
}

void dfs(std::string& str, int idx) {
	if (idx == str.size()) {
		if (!calcVal(str)) arr.push_back(str);
	}
	else {
		dfs(str, idx + 2);
		str[idx] = '+';
		dfs(str, idx + 2);
		str[idx] = '-';
		dfs(str, idx + 2);
		str[idx] = ' ';
	}
}

int main() {
	int testCases;
	scanf_s("%d", &testCases);
	for (int i = 0; i < testCases; ++i) {
		int n;
		scanf_s("%d", &n);
		std::string str = "1";
		for (int j = 2; j <= n; ++j) {
			str.push_back(' ');
			str.push_back(j + '0');
		}
		dfs(str, 1);
		if (i) printf("\n");
		for (auto it = arr.begin(); it != arr.end(); ++it) {
			printf("%s\n", it->c_str());
		}
		arr.clear();
	}
}