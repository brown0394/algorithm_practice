#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int len;
	std::cin >> len;
	len = (len << 1) + 1;
	std::vector<int> manacherArr(len);
	manacherArr[0] = -1;
	for (int i = 1; i < len; i += 2) {
		std::cin >> manacherArr[i];
		manacherArr[i + 1] = -1;
	}
    std::vector<int> palindromeLen(len);
    int rightEnd = 1;
    int palindromeCenter = 1;
    for (int i = 1; i < len; ++i) {
        int leftSide = 0;
        if (rightEnd > i) {
            if (i + palindromeLen[palindromeCenter - (i - palindromeCenter)] < rightEnd) {
                palindromeLen[i] = palindromeLen[palindromeCenter - (rightEnd - palindromeCenter)];
                continue;
            }
            else leftSide = i - (++rightEnd - i);
        }
        else {
            leftSide = i - 1;
            rightEnd = i + 1;
        }
        palindromeCenter = i;
        while (leftSide >= 0 && rightEnd < len && manacherArr[leftSide] == manacherArr[rightEnd]) {
            ++rightEnd;
            --leftSide;
        }
        palindromeLen[i] = --rightEnd - i;
    }
    int queries;
    std::cin >> queries;
    for (int i = 0, from, to; i < queries; ++i) {
        std::cin >> from >> to;
        int target = ((from + to) >> 1) - 1;
        int isOdd = (from + to) % 2;
        int targetIdx = (target << 1) + 1 + isOdd;
        if (target + (palindromeLen[targetIdx] / 2) >= to - 1) std::cout << 1 << '\n';
        else std::cout << 0 << '\n';
    }
}