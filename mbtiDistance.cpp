#include <iostream>
#include <vector>
#include <string>

#define TRIPLE 33

int getDistance(std::string& one, std::string& two) {
	int dist = 4;
	for (int i = 0; i < 4; ++i) {
		if (one[i] == two[i]) --dist;
	}
	return dist;
}

int calcDistances(std::vector<std::string>& arr) {
	int inputs;
	scanf_s("%d", &inputs);
	char input[5];
	if (inputs >= TRIPLE) {
		for (int i = 0; i < inputs; ++i) {
			scanf_s("%s", input, 5);
		}
		return 0;
	}
	if (arr.capacity() < inputs) {
		arr.reserve(inputs);
	}
	for (int i = 0; i < inputs; ++i) {
		scanf_s("%s", input, 5);
		arr.push_back(input);
	}
	int min = 100;
	int dist;
	int baseDist;
	for (int i = 0; i < inputs - 2; ++i) {
		for (int j = i + 1; j < inputs - 1; ++j) {
			baseDist = getDistance(arr[i], arr[j]);
			if (baseDist >= min) continue;
			for (int k = j + 1; k < inputs; ++k) {
				dist = baseDist + getDistance(arr[i], arr[k]);
				if (dist >= min) continue;
				dist += getDistance(arr[j], arr[k]);
				if (dist < min) {
					min = dist;
					if (!min) {
						arr.clear();
						return 0;
					}
				}
			}
		}
	}
	arr.clear();
	return min;
}

int main() {
	int testCase;
	scanf_s("%d", &testCase);
	std::vector<std::string> arr;
	for (int i = 0; i < testCase; ++i) {
		printf("%d\n", calcDistances(arr));
	}
}