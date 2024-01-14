#include <iostream>

int getPrice(int num, int amount, int second) {
	switch (amount) {
	case 1: { return num * 100; }
	case 2: { 
		if (second < 0) return 1000 + num * 100;
		else return 2000 + num * 500 + second * 500;
	}
	case 3: { return 10000 + num * 1000;  }
	case 4: { return 50000 + num * 5000;  }
	}
	return 0;
}

int main() {
	int num;
	scanf_s("%d", &num);
	int in;
	int max = 0;
	int curMax;
	int second;
	for (int i = 0; i < num; ++i) {
		curMax = 0;
		int dice[7]{ 0 };
		second = -1;
		for (int j = 0; j < 4; ++j) {
			scanf_s("%d", &in);
			++dice[in];
			if (dice[in] > dice[curMax]) curMax = in;
			else if (dice[in] == dice[curMax]) {
				if (dice[in] == 2 && curMax != in) second = in;
				else if (in > curMax) curMax = in;
			}
		}
		in = getPrice(curMax, dice[curMax], second);
		if (in > max) max = in;
	}
	printf("%d\n", max);
}
