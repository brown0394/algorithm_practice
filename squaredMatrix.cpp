#include <iostream>
#include <vector>

#define MODVAL 1000

class matrix {
private:
	int m;
	long long n;
	std::vector<std::vector<int>> originalMat;
	std::vector<std::vector<int>> calcMat;
	std::vector<std::vector<int>> calcMat2;
	std::vector<std::vector<int>>* squaredMat;
	std::vector<std::vector<int>>* resultMat;
	void matMul(std::vector<std::vector<int>>& one, std::vector<std::vector<int>>& two);
	void calcSqauredMat(long long n);
public:
	matrix(int p_m, long long p_n);
	void printNSquaredMat();
};

matrix::matrix(int p_m, long long p_n) : m(p_m), n(p_n), originalMat(m, std::vector<int>(m)),
calcMat(m, std::vector<int>(m)), calcMat2(m, std::vector<int>(m)) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf_s("%d", &originalMat[i][j]);
			originalMat[i][j] = originalMat[i][j] % MODVAL;
			calcMat[i][j] = originalMat[i][j];
		}
	}
	squaredMat = &calcMat;
	resultMat = &calcMat2;
}

void matrix::calcSqauredMat(long long n) {
	if (n == 1) return;
	if (n % 2) calcSqauredMat((n - 1) >> 1);
	else calcSqauredMat(n >> 1);
	for (int k = 0; k < m; ++k) {
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < m; ++j)
			{
				if (!k) (*resultMat)[i][j] = 0;
				(*resultMat)[i][j] = ((*resultMat)[i][j] + (((*squaredMat)[i][k] * (*squaredMat)[k][j]) % MODVAL)) % MODVAL;
			}
		}
	}

	if (n % 2) {
		for (int k = 0; k < m; ++k) {
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < m; ++j)
				{
					if (!k) (*squaredMat)[i][j] = 0;
					(*squaredMat)[i][j] = ((*squaredMat)[i][j] + (((*resultMat)[i][k] * originalMat[k][j]) % MODVAL)) % MODVAL;
				}
			}
		}
	}
	else {
		std::vector<std::vector<int>>* temp = resultMat;
		resultMat = squaredMat;
		squaredMat = temp;
	}
}

void matrix::printNSquaredMat() {
	calcSqauredMat(n);

	for (int i = 0; i < m; ++i) {
		printf("%d", (*squaredMat)[i][0]);
		for (int j = 1; j < m; ++j) {
			printf(" %d", (*squaredMat)[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int m;
	long long n;
	scanf_s("%d %lld", &m, &n);
	matrix mat(m, n);
	mat.printNSquaredMat();
}