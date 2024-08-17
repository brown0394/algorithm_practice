#include <iostream>
#include <vector>
#include <queue>

struct node {
	std::vector<int> laterSeq;
	int earlier;
};
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);	
	int participants, seqs;
	std::cin >> participants >> seqs;
	std::vector<node> seqInfo(participants + 1);
	for (int i = 0; i < seqs; ++i) {
		int len;
		std::cin >> len;
		int last, cur;
		std::cin >> last;
		for (int j = 2; j <= len; ++j) {
			std::cin >> cur;
			seqInfo[last].laterSeq.push_back(cur);
			++seqInfo[cur].earlier;
			last = cur;
		}
	}
	std::queue<int> q;
	std::vector<int> result;
	result.reserve(participants);
	for (int i = 1; i <= participants; ++i) {
		if (seqInfo[i].earlier == 0) {
			q.push(i);
			result.push_back(i);
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto it = seqInfo[cur].laterSeq.begin(), end = seqInfo[cur].laterSeq.end();
			it != end; ++it) {
			if (--seqInfo[*it].earlier == 0) {
				q.push(*it);
				result.push_back(*it);
			}
		}
	}
	if (result.size() < participants) std::cout << 0 << '\n';
	else {
		for (auto it = result.begin(), end = result.end(); it != end; ++it) {
			std::cout << *it << '\n';
		}
	}
}