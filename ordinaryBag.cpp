#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

struct node {
	int sum;
	int weight;
	int bound;
	int next;
	int idx;
};

bool sortStd(std::vector<int>& one, std::vector<int>& two) {
	return ((float)one[1] / one[0]) > ((float)two[1] / two[0]);
}

int getBound(std::vector<std::vector<int>>& arr, int idx, int curWeight, int curVal, int weightLimit) {
	int bound = curVal;
	for (int i = idx; i < arr.size(); ++i) {
		if (curWeight + arr[i][0] > weightLimit) {
			int tempWeight = weightLimit - curWeight;
			bound += (tempWeight / (float)arr[i][0]) * arr[i][1];
			break;
		}
		curWeight += arr[i][0];
		bound += arr[i][1];
	}
	return bound;
}

int main() {
	int N, weightLimit;
	scanf_s("%d %d", &N, &weightLimit);
	std::vector<std::vector<int>> arr(N, std::vector<int>(2));
	for (int i = 0; i < N; ++i) {
		scanf_s("%d %d", &arr[i][0], &arr[i][1]);
	}
	std::sort(arr.begin(), arr.end(), sortStd);
	std::stack<node> stk;
	stk.push(node{ 0, 0, getBound(arr, 0, 0, 0, weightLimit), 0, 0});

	int max = 0;
	int maxBound = 0;
	int bound;
	node* cur;
	while (!stk.empty()) {
		cur = &stk.top();
		if (cur->sum > max) {
			max = cur->sum;
		}
		if (cur->idx == N) {
			maxBound = max;
			stk.pop();
			continue;
		}
		if (cur->next < 2) {
			if (cur->next) {
				bound = getBound(arr, cur->idx+1, cur->weight, cur->sum, weightLimit);
				if (bound < maxBound) {
					stk.pop();
					continue;
				}
				stk.push(node{ cur->sum, cur->weight, bound, 0, cur->idx + 1 });
			}
			else if (cur->weight + arr[cur->idx][0] <= weightLimit) {
				stk.push(node{ cur->sum + arr[cur->idx][1], cur->weight + arr[cur->idx][0], cur->bound, 0, cur->idx + 1 });
			}
			++cur->next;
		}
		else {
			stk.pop();
		}
	}
	printf("%d\n", max);
}