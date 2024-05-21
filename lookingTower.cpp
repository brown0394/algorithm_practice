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
	int numOfBuildings;
	scanf_s("%d", &numOfBuildings);
	std::vector<node> buildings(numOfBuildings);

	for (int i = 0; i < numOfBuildings; ++i) {
		scanf_s("%d", &buildings[i].num);
	}
	for (int i = 1; i < numOfBuildings; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (buildings[j].num > buildings[i].num) {
				buildings[i].nearestVisibleL = j;
				buildings[i].buildingsVisibleL = buildings[j].buildingsVisibleL + 1;
				break;
			}
			else if (buildings[j].nearestVisibleL < 0) break;
			else j = buildings[j].nearestVisibleL + 1;
		}
	}
	for (int i = numOfBuildings - 2; i >= 0; --i) {
		for (int j = i + 1; j < numOfBuildings; ++j) {
			if (buildings[j].num > buildings[i].num) {
				buildings[i].nearestVisibleR = j;
				buildings[i].buildingsVisibleR = buildings[j].buildingsVisibleR + 1;
				break;
			}
			else if (buildings[j].nearestVisibleR < 0) break;
			else j = buildings[j].nearestVisibleR - 1;
		}
	}
	for (int i = 0; i < numOfBuildings; ++i) {
		int visible = buildings[i].buildingsVisibleL + buildings[i].buildingsVisibleR;
		if (visible) {
			if (buildings[i].nearestVisibleL < 0) printf("%d %d\n", visible, buildings[i].nearestVisibleR + 1);
			else if (buildings[i].nearestVisibleR < 0) printf("%d %d\n", visible, buildings[i].nearestVisibleL + 1);
			else if (i - buildings[i].nearestVisibleL <= buildings[i].nearestVisibleR - i) {
				printf("%d %d\n", visible, buildings[i].nearestVisibleL + 1);
			}
			else printf("%d %d\n", visible, buildings[i].nearestVisibleR + 1);
		}
		else printf("0\n");
	}
}