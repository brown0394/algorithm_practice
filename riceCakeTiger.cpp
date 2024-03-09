#include <iostream>
#include <vector>

int main() {
	int days, riceCakes;
	scanf_s("%d %d", &days, &riceCakes);
	std::vector<int> rCakeGave(days);
	rCakeGave[days - 1] = riceCakes;
	int check = days - 3;
	rCakeGave[check + 1] = (riceCakes >> 1) + 1;
	for (int i = check; i >= 0; --i) {
		rCakeGave[i] = rCakeGave[i + 2] - rCakeGave[i + 1];
		if (rCakeGave[i] >= rCakeGave[i + 1]) {
			++rCakeGave[check + 1];
			i = check + 1;
		}
	}
	printf("%d\n%d\n", rCakeGave[0], rCakeGave[1]);
}
