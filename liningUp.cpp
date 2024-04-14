#include <iostream>
#include <list>

struct node {
	int bigger;
	int count;
	int num;
};

int main() {
	std::list<node> line;
	int numb;
	scanf_s("%d", &numb);
	int in;
	for (int i = 1; i <= numb; ++i) {
		scanf_s("%d", &in);
		auto it = line.begin();
		bool added = false;
		while (it != line.end()) {
			if (it->count < it->bigger) {
				line.insert(it, node{ in, 0, i });
				added = true;
				break;
			}
			++it;
		}
		if (!added) line.insert(it, node{ in, 0, i });
		else {
			while (it != line.end()) {
				if (it->count + 1 <= it->bigger) ++(it++)->count;
				else {
					node& toSwap = *it;
					line.insert(--it, toSwap);
					it = line.erase(++it);
				}
			}
		}
	}
	auto it = line.begin();
	printf("%d", it->num);
	for (++it; it != line.end(); ++it) {
		printf(" %d", it->num);
	}
}