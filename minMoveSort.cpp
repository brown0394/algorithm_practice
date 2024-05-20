#include <iostream>
#include <vector>

struct node {
	int num;
	int last;
	int count;
	node() : num(-1), last(-1), count(1) {}
};

int main() {
	int n;
	scanf_s("%d", &n);
	std::vector<node> seq(n);
	for (int i = 0; i < n; ++i) {
		scanf_s("%d", &seq[i].num);
	}
	int maxSeq = 1;
	--n;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (seq[i].num < seq[j].num) {
				if (seq[j].last < 0) {
					seq[j].last = i;
					++seq[j].count;
				}
				else {
					if (seq[seq[j].last].count < seq[i].count) {
						seq[j].count += (seq[i].count - seq[seq[j].last].count);
						seq[j].last = i;
						if (seq[j].count > maxSeq) maxSeq = seq[j].count;
					}
				}
			}
		}
	}
	printf("%d\n", n + 1 - maxSeq);
}