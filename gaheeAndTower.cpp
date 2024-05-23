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
	if (fromL + fromR > (numOfBuildings + 1)) {
		printf("-1\n");
		return 0;
	}
	int midVal = fromL + fromR - 1;
	if (fromL == 1) {
		printf("%d", fromR);
		int repeat = numOfBuildings - fromR;
		for (int i = 0; i < repeat; ++i) {
			printf(" 1");
		}
		for (int i = fromR-1; i >= 1; --i) {
			printf(" %d", i);
		}
		printf("\n");
	}
	else {
		printf("1");
		int repeat = numOfBuildings - fromR - (fromL - 1);
		for (int i = 0; i < repeat; ++i) {
			printf(" 1");
		}
		for (int i = 2; i < fromL; ++i) {
			printf(" %d", i);
		}
		int val;
		if (fromR > fromL) val = fromR;
		else {
			printf(" %d", fromL);
			val = fromR - 1;
		}
		for (int i = val; i >= 1; --i) {
			printf(" %d", i);
		}
		printf("\n");
	}
}