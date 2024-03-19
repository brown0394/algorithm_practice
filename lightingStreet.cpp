#include <iostream>

int main() {
	int width, lamps, maxDist;
	scanf_s("%d %d %d", &width, &lamps, &maxDist);
	int in, last = maxDist, diff;
	for (int i = 1; i < lamps; ++i) {
		scanf_s("%d", &in);
		if (in == width) break;
		diff = (in - last) >> 1;
		if ((in - last) % 2) ++diff;
		last = in;
		if (diff > maxDist) maxDist = diff;
	}
	diff = width - last;
	if (diff > maxDist) maxDist = diff;
	printf("%d\n", maxDist);
}
