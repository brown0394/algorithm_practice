#include <iostream>
#include <map>
#include <string>

int main() {
	std::map<std::string, int> clothes;
	int testCases, cases;
	scanf_s("%d", &testCases);
	char wear[31];
	int product;
	for (int i = 0; i < testCases; ++i) {
		scanf_s("%d", &cases);
		for (int j = 0; j < cases; ++j) {
			scanf_s("%s", wear, 30);
			scanf_s("%s", wear, 30);
			auto found = clothes.find(wear);
			if (found == clothes.end()) {
				clothes.insert(std::make_pair(wear, 1));
			}
			else {
				++found->second;
			}
		}
		product = 1;
		for (auto it = clothes.begin(); it != clothes.end(); ++it) {
			product *= (it->second + 1);
		}
		--product;
		printf("%d\n", product);
		clothes.clear();
	}
}