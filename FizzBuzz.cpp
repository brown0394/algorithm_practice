#include <iostream>
#include <string>
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);	
	std::string one, two, three;
	std::cin >> one >> two >> three;
	int num = 0;
	if (three[0] >= '0' && three[0] <= '9') {
		num = std::stoi(three) + 1;
	}
	else if (two[0] >= '0' && two[0] <= '9') {
		num = std::stoi(two) + 2;
	}
	else if (one[0] >= '0' && one[0] <= '9') {
		num = std::stoi(one) + 3;
	}
	if (num % 3) {
		if (num % 5) std::cout << num << '\n';
		else std::cout << "Buzz\n";
	}
	else {
		if (num % 5) std::cout << "Fizz\n";
		else std::cout << "FizzBuzz\n";
	}
}