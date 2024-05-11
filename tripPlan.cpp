#include <iostream>
#include <vector>
#include <bitset>

int main() {
	int n, destinations;
	scanf("%d %d", &n, &destinations);
	std::vector<std::bitset<201>> path(n);
	int in;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
            if (i == j) path[i][j] = true;
			scanf("%d", &in);
			if (in) {
				path[i][j] = true;
				path[j][i] = true;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (path[j][i]) {
				for (int k = 0; k < n; ++k) {
					if (!path[j][k] && path[i][k]) path[j][k] = true;
					if (!path[i][k] && path[j][k]) path[i][k] = true;
				}
			}
		}
	}
	int cur;
	scanf("%d", &cur);
	--cur;
	bool canReach = true;
	for (int i = 1; i < destinations; ++i) {
		scanf("%d", &in);
		--in;
		if (path[cur][in]) cur = in;
		else canReach = false;
	}
	if (canReach) printf("YES\n");
	else printf("NO\n");
}