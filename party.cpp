#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2000000

class node {
public:
	int to;
	int* cost;
	node(int p_to, int* p_cost) :to(p_to), cost(p_cost) {}
	bool operator< (const node& other);
};

struct connect {
	int to;
	int cost;
};

bool node::operator<(const node& other) {
	return *this->cost < *other.cost;
}

int main() {
	int towns, paths, partyTown;
	scanf_s("%d %d %d", &towns, &paths, &partyTown);
	std::vector<std::vector<connect>> connections(towns + 1);
	std::vector<int> wayToParty(towns + 1, INF);
	std::vector<int> waybackHome(towns + 1, INF);
	int from, to, cost;
	std::vector<node> pq;
	for (int i = 0; i < paths; ++i) {
		scanf_s("%d %d %d", &from, &to, &cost);
		if (partyTown == from) {
			waybackHome[to] = cost;
			pq.push_back({ to, &waybackHome[to] });
		}
		else connections[from].push_back({ to, cost });
		if (partyTown == to) {
			wayToParty[from] = cost;
		}

	}
	std::make_heap(pq.begin(), pq.end());
	int minWayBack;
	int max = 2000000;
	while (!pq.empty()) {
		std::pop_heap(pq.begin(), pq.end());
		to = pq.back().to;
		cost = *pq.back().cost;
		pq.pop_back();
		minWayBack = 100;
		for (int i = 0; i < connections[to].size(); ++i) {
			if (connections[to][i].to == partyTown) {
				if (connections[to][i].cost < minWayBack) minWayBack = connections[to][i].cost;
			}
			else if(connections[to][i].cost + wayToParty[connections[to][i].to] < minWayBack) {
				minWayBack = connections[to][i].cost + wayToParty[connections[to][i].to];
			}

			if (cost + connections[to][i].cost < waybackHome[connections[to][i].to]) {
				waybackHome[connections[to][i].to] = cost + connections[to][i].cost;
			}
		}
		wayToParty[to] = minWayBack;
		if (max > wayToParty[to] + cost) max = wayToParty[to] + cost;

	}
	
	
	for (int i = 1; i <= towns; ++i) {
		if (i == partyTown) continue;
		if (connections[i][partyTown] + connections[partyTown][i] > max) {
			max = connections[i][partyTown] + connections[partyTown][i];
		}
	}
	printf("%d\n", max);
}