#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int N;
	std::cin >> N;
	std::vector<int> longestSeq;
	longestSeq.reserve(N);
	int in;
	std::cin >> in;
	longestSeq.push_back(in);
	for (int i = 1; i < N; ++i) {
		std::cin >> in;
		if (in > longestSeq.back()) longestSeq.push_back(in);
		else {
			auto loc = std::lower_bound(longestSeq.begin(), longestSeq.end(), in);
			*loc = in;
		}
	}
	std::cout << longestSeq.size() << '\n';
}