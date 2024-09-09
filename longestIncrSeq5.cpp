#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int N;
	std::cin >> N;
	std::vector<int> longestSeq;
	std::vector<int> numInputs(N);
	std::vector<int> seqLens(N);
	longestSeq.reserve(N);
	std::cin >> numInputs[0];
	longestSeq.push_back(numInputs[0]);
	for (int i = 1; i < N; ++i) {
		std::cin >> numInputs[i];
		if (numInputs[i] > longestSeq.back()) {
			seqLens[i] = longestSeq.size();
			longestSeq.push_back(numInputs[i]);
		}
		else {
			auto loc = std::lower_bound(longestSeq.begin(), longestSeq.end(), numInputs[i]);
			*loc = numInputs[i];
			seqLens[i] = loc - longestSeq.begin();
		}
	}
	int cur = longestSeq.size();
	std::cout << cur << '\n';
	std::vector<int> result(cur--);
	for (int i = N - 1; i >= 0; --i) {
		if (seqLens[i] == cur) {
			result[cur--] = numInputs[i];
			if (cur < 0) break;
		}
	}
	for (int& elem : result) std::cout << elem << ' ';
	std::cout << '\n';
}