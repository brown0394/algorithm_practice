#include <iostream>
#include <vector>
#include <queue>

int row, col;
std::vector<std::vector<int>> groundMap;
std::vector<int> groupSize{0, 0};

void markSpaceGroupInfo(int i, int j, int group) {
	groupSize.push_back(1);
	groundMap[i][j] = group;
	std::queue<std::pair<int, int>> q;
	q.emplace(i, j);
	auto markAndPushToQ = [&q, group](int r, int c) {
		groundMap[r][c] = group;
		++groupSize[group];
		q.emplace(r, c);
	};
	while (!q.empty()) {
		i = q.front().first;
		j = q.front().second;
		q.pop();
		if (i && !groundMap[i - 1][j]) {
			markAndPushToQ(i - 1, j);
		}
		if (i + 1 < row && !groundMap[i + 1][j]) {
			markAndPushToQ(i + 1, j);
		}
		if (j && !groundMap[i][j - 1]) {
			markAndPushToQ(i, j - 1);
		}
		if (j + 1 < col && !groundMap[i][j + 1]) {
			markAndPushToQ(i, j + 1);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> row >> col;
	groundMap.resize(row, std::vector<int>(col));
	for (int i = 0; i < row; ++i) {
		std::cin.get();
		for (int j = 0; j < col; ++j) {
			groundMap[i][j] = std::cin.get() - '0';
		}
	}
	int groups = 2;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (!groundMap[i][j]) markSpaceGroupInfo(i, j, groups++);
		}
	}

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (groundMap[i][j] == 1) {
				int groupsChecked[4];
				int cur = 0;
				int val = 1;
				auto check = [&groupsChecked, &cur, &val](int group) {
					if (cur) {
						for (int i = 0; i < cur; ++i) {
							if (group == groupsChecked[i]) return;
						}
					}
					val += groupSize[group];
					groupsChecked[cur++] = group;
				};
				if (i && groundMap[i - 1][j] > 1) {
					check(groundMap[i - 1][j]);
				}
				if (i + 1 < row && groundMap[i + 1][j] > 1) {
					check(groundMap[i + 1][j]);
				}
				if (j && groundMap[i][j - 1] > 1) {
					check(groundMap[i][j - 1]);
				}
				if (j + 1 < col && groundMap[i][j + 1] > 1) {
					check(groundMap[i][j + 1]);
				}
				std::cout << val;
			}
			else std::cout << 0;
		}
		std::cout << '\n';
	}
}