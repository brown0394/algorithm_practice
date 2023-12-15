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
	return *this->cost > *other.cost;
}

void dijkstra(std::vector<node>& pq, std::vector<std::vector<connect>>& connections, std::vector<int>& distances) {
	int tempCost;
	int to, cost;
	while (!pq.empty()) {//pq contains path from party town to all the other towns.
		std::pop_heap(pq.begin(), pq.end());
		to = pq.back().to;
		cost = *pq.back().cost;
		pq.pop_back();
		for (int i = 0; i < connections[to].size(); ++i) {
			if (cost + connections[to][i].cost < distances[connections[to][i].to]) {//checking min distance from party town.
				tempCost = distances[connections[to][i].to];
				distances[connections[to][i].to] = cost + connections[to][i].cost;
				if (tempCost == INF) {
					pq.push_back({ connections[to][i].to, &distances[connections[to][i].to] });
					std::push_heap(pq.begin(), pq.end());
				}
				else {
					std::make_heap(pq.begin(), pq.end());
				}
			}
		}
	}
}

int main() {
	int towns, paths, partyTown;
	scanf_s("%d %d %d", &towns, &paths, &partyTown);
	std::vector<std::vector<connect>> connections(towns + 1);
	std::vector<std::vector<connect>> reverseConnections(towns + 1);
	std::vector<int> wayToParty(towns + 1, INF);
	std::vector<int> waybackHome(towns + 1, INF);
	waybackHome[partyTown] = 0;
	wayToParty[partyTown] = 0;
	int from, to, cost;
	std::vector<node> pq;
	std::vector<node> reversePq;
	for (int i = 0; i < paths; ++i) {
		scanf_s("%d %d %d", &from, &to, &cost);
		if (partyTown == from) {
			waybackHome[to] = cost;
			pq.push_back({ to, &waybackHome[to] });
		}
		else connections[from].push_back({ to, cost });
		if (partyTown == to) {
			wayToParty[from] = cost;
			reversePq.push_back({ from, &wayToParty[from] });
		}
		else reverseConnections[to].push_back({ from, cost });
	}
	std::make_heap(pq.begin(), pq.end());
	std::make_heap(reversePq.begin(), reversePq.end());
	dijkstra(pq, connections, waybackHome);
	dijkstra(reversePq, reverseConnections, wayToParty);
	int max = 0;
	for (int i = 1; i <= towns; ++i) {
		if (max < waybackHome[i] + wayToParty[i])
			max = waybackHome[i] + wayToParty[i];
	}
	printf("%d\n", max);
}