#include <iostream>
#include <string>
#include <vector>

int main() {
	std::string str;
	std::cin >> str;
	char strNum[51]{'\0'};
	int idx = 0;
	int num;
	std::vector<int> arr;
	char op = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '+' || str[i] == '-') {
			strNum[idx] = '\0';
			idx = 0;
			num = std::atoi(strNum);
			if (op == '+') {
				arr.back() += num;
				
			}
			else {
				arr.push_back(num);
			}
			op = str[i];
		}
		else {
			strNum[idx++] = str[i];
		}
	}
	strNum[idx] = '\0';
	num = std::atoi(strNum);
	if (op == '+') {
		arr.back() += num;

	}
	else {
		arr.push_back(num);
	}
	num = arr[0];
	for (int i = 1; i < arr.size(); ++i) {
		num -= arr[i];
	}
	printf("%d\n", num);
}