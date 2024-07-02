#include <iostream>
#include <vector>
#include <algorithm>

struct score {
	int langDiff, sciDiff;
	bool operator < (const score& other) {
		if (langDiff == other.langDiff) return sciDiff < other.sciDiff;
		return langDiff < other.langDiff;
	}
};

int main() {
	int studentN;
	const int postNum = 4763;
	const int engB = 108;
	const int korB = 508;
	const int mathB = 212;
	const int sciB = 305;
	scanf_s("%d", &studentN);
	if (studentN == 0) {
		printf("1\n0 0\n");
		return 0;
	}
	if (studentN % postNum || postNum > studentN) {
		printf("0\n");
		return 0;
	}
	studentN /= postNum;
	std::vector<score> possibleCombi;
	for (int i = 0; i <= 200; ++i) {
		int eng = i * engB;
		int kor = i * korB;
		for (int j = 0; j <= 200; ++j) {
			int math = j * mathB;
			int sci = j * sciB;
			if (eng + math > studentN) break;
			if (eng + math == studentN) possibleCombi.push_back({ i, j });
			else if (eng + sci == studentN) possibleCombi.push_back({ i, j });
			else if (kor + math == studentN) possibleCombi.push_back({ i, j });
			else if (kor + sci == studentN) possibleCombi.push_back({ i, j });
		}
	}
	std::sort(possibleCombi.begin(), possibleCombi.end());
	printf("%d\n", possibleCombi.size());
	for (auto it = possibleCombi.begin(), end = possibleCombi.end(); it != end; ++it) {
		printf("%d %d\n", it->langDiff, it->sciDiff);
	}
}