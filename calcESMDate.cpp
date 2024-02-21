#include <iostream>
#include <vector>

#define EMOD 15
#define MMOD 19
#define SUN 28

int main() {
	int earthY, sunY, moonY;
	scanf_s("%d %d %d", &earthY, &sunY, &moonY);
	--earthY;
	--moonY;
	--sunY;
	while (true) {
		if ((sunY % EMOD) == earthY && (sunY % MMOD) == moonY) break;
		sunY += SUN;
	}
	printf("%d\n", sunY + 1);
}
