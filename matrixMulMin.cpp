#include <iostream>
#include <vector>
#include <limits>

struct matInfo {
	int r, c, mulCount;
};

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);	
	int matrixes;
	const int max = std::numeric_limits<int>::max();
	std::cin >> matrixes;
	std::vector<std::vector<matInfo>> matrixMultInfos(matrixes, std::vector<matInfo>(matrixes));
	for (int i = 0, r, c; i < matrixes; ++i) {
		std::cin >> r >> c;
		matrixMultInfos[i][i].r = r;
		matrixMultInfos[i][i].c = c;
		for (int j = i - 1; j >= 0; --j) {
			matrixMultInfos[j][i].r = matrixMultInfos[j][i-1].r;
			matrixMultInfos[j][i].c = c;
			matrixMultInfos[j][i].mulCount = max;
			for (int k = i, l = i-1; k > j; --k, --l) {
				int calc = (c * matrixMultInfos[k][i].r * matrixMultInfos[j][l].r)
					+ matrixMultInfos[k][i].mulCount + matrixMultInfos[j][l].mulCount;
				if (matrixMultInfos[j][i].mulCount > calc) matrixMultInfos[j][i].mulCount = calc;
			}
		}
	}
	std::cout << matrixMultInfos[0][matrixes - 1].mulCount << '\n';
}