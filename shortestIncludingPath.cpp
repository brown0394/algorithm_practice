#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <memory>


bool sortStd(std::pair<int, std::shared_ptr<int>>& one, std::pair<int, std::shared_ptr<int>>& two) {
	return *one.second > *two.second;
}

void dijkstra(std::vector<std::map<int, std::shared_ptr<int>>>& connnections, int idx) {
	std::vector<std::pair<int, std::shared_ptr<int>>> pq;
	for (auto it = connnections[idx].begin(); it != connnections[idx].end(); ++it) {
		pq.push_back({ it->first, it->second });
	}
	std::make_heap(pq.begin(), pq.end(), sortStd);
	int to, cost;
	std::map<int, std::shared_ptr<int>>::iterator found;
	int* newCost;
	while (!pq.empty()) {
		std::pop_heap(pq.begin(), pq.end(), sortStd);
		to = pq.back().first;
		cost = *pq.back().second;
		pq.pop_back();
		for (auto it = connnections[to].begin(); it != connnections[to].end(); ++it) {
			if (it->first == idx) continue;
			found = connnections[idx].find(it->first);
			if (found == connnections[idx].end()) {
				std::shared_ptr<int> newCost(new int(cost + *it->second));
				connnections[idx].insert({ it->first, newCost });
				connnections[it->first].insert({ idx, newCost });
				pq.push_back({ it->first, newCost });
				std::push_heap(pq.begin(), pq.end(), sortStd);
			}
			else if (*found->second > cost + *it->second) {
				*found->second = cost + *it->second;
				found = connnections[it->first].find(idx);
				*found->second = cost + *it->second;
				std::make_heap(pq.begin(), pq.end(), sortStd);
			}
		}
	}

}

int getCost(std::vector<std::map<int, std::shared_ptr<int>>>& connnections, std::vector<int>& seq) {
	int cost = 0;
	std::map<int, std::shared_ptr<int>>::iterator found;
	for (int i = 0; i < seq.size()-1; ++i) {
		found = connnections[seq[i]].find(seq[i + 1]);
		if (found == connnections[seq[i]].end()) {
			return -1;
		}
		cost += *found->second;
	}
	return cost;
}

int main() {
	int vertexes, edges;
	scanf_s("%d %d", &vertexes, &edges);
	std::vector<std::map<int, std::shared_ptr<int>>> connnections(vertexes + 1);
	int from, to, cost, idx = 0;
	for (int i = 0; i < edges; ++i) {
		scanf_s("%d %d %d", &from, &to, &cost);
		std::shared_ptr<int> newCost(new int(cost));
		connnections[from].insert({ to, newCost });
		connnections[to].insert({ from, newCost });
	}
	dijkstra(connnections, 1);
	int must1, must2;
	scanf_s("%d %d", &must1, &must2);
	dijkstra(connnections, must1);
	dijkstra(connnections, must2);
	
	std::vector<int>seq1{ 1, must1, must2, vertexes };
	std::vector<int>seq2{ 1, must2, must1, vertexes };
	for (int i = 0; i < 2; ++i) {
		if (seq1[1 + i] == 1 || seq1[1 + i] == vertexes) {
			seq1.erase(seq1.begin() + 1 + i);
			seq2.erase(seq2.begin() + 2 - i);
		}
	}
	cost = getCost(connnections, seq1);
	int cost2 = getCost(connnections, seq2);
	if (cost >= 0) {
		if (cost2 >= 0) {
			if (cost > cost2) printf("%d\n", cost2);
			else printf("%d\n", cost);
		}
		else printf("-1\n");

	}
	else if (cost2 >= 0){
		printf("%d\n", cost2);
	}
	else printf("-1\n");
}