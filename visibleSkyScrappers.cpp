#include <iostream>
#include <vector>

int main() {
	int nBuildings;
	scanf_s("%d", &nBuildings);
	std::vector<int> buildings(nBuildings);
	for (int i = 0; i < nBuildings; ++i) {
		scanf_s("%d", &buildings[i]);
	}
	int max = 0;
	for (int i = 0; i < nBuildings; ++i) {
		int count = 0;
		if (i) {
			int left = i - 1;
			float slope = (buildings[left] - buildings[i]) / (float)(left - i);
			float curSlope = 0.0f;
			++count;
			while (--left >= 0) {
				curSlope = (buildings[left] - buildings[i]) / (float)(left - i);
				if (curSlope < slope) {
					++count;
					slope = curSlope;
				}
			}
		}
		if (i + 1 < nBuildings) {
			int right = i + 1;
			float slope = (buildings[right] - buildings[i]) / (float)(right - i);
			float curSlope = 0.0f;
			++count;
			while (++right < nBuildings) {
				curSlope = (buildings[right] - buildings[i]) / (float)(right - i);
				if (curSlope > slope) {
					++count;
					slope = curSlope;
				}
			}
		}
		if (max < count) max = count;
	}

	printf("%d\n", max);
}