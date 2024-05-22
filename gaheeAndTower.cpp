#include <iostream>
#include <vector>

struct node {
	int buildingsVisibleR;
	int buildingsVisibleL;
	int nearestVisibleL;
	int nearestVisibleR;
	int num;
	node() : buildingsVisibleR(0), buildingsVisibleL(0), nearestVisibleL(-1),
	num(0), nearestVisibleR(-1){}
};

int main() {
	int numOfBuildings, fromL, fromR;
	scanf_s("%d %d %d", &numOfBuildings, &fromL, &fromR);
	if (fromL + fromR > (numOfBuildings + 1) || !(fromL + fromR)) {
		printf("-1\n");
		return 0;
	}
	int midVal = fromL + fromR - 1;
	if (fromL == 1 && fromR > fromL) {
		//1 on right;
	}
	bool first = true;
	int repeat = fromL - 1;
	for (int i = 1; i <= repeat; ++i) {
		if (first) {
			first = false;
			printf("%d", i);
		}
		else printf(" %d", i);
	}
	for (int i = numOfBuildings - midVal - 1; i > 0; --i) {
		printf(" %d", repeat);
	}
	if (fromL > 1) printf(" %d", midVal);
	int til = (midVal - fromR);
	for (int i = midVal - 1; i > til; --i) {
		printf(" %d", i);
	}
	printf("\n");
}