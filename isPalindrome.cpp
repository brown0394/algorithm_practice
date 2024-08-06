#include <iostream>
#include <vector>

enum EPalin{
	needCheck = 0,
	palind,
	nonPalind
};

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int len;
	std::cin >> len;
	std::vector<int> arr(len + 1);
	std::vector<std::vector<int>> isPalindrome(len + 1, std::vector<int>(len + 1, EPalin::needCheck));
	for (int i = 1; i <= len; ++i) {
		std::cin >> arr[i];
		isPalindrome[i][i] = EPalin::palind;
	}
	int queries;
	std::cin >> queries;
	for (int i = 0; i < queries; ++i) {
		int from, to;
		std::cin >> from >> to;
		int palindrome = 1;
		int l = from, r = to;
		while (true) {
			if (isPalindrome[l][r] == EPalin::needCheck) {
				if (r - l == 1) {
					if (arr[l] == arr[r]) isPalindrome[l][r] = EPalin::palind;
					else isPalindrome[l][r] = EPalin::nonPalind;
					break;
				}
				++l;
				--r;
			}
			else break;
		}
		if (isPalindrome[l][r] == EPalin::palind) {
			--l;
			++r;
			while (l >= from) {
				if (arr[l] == arr[r]) {
					isPalindrome[l--][r++] = EPalin::palind;
				}
				else break;
			}
		}
		while (l >= from) {
			isPalindrome[l--][r++] = EPalin::nonPalind;
		}
		if (isPalindrome[from][to] == EPalin::palind) std::cout << 1 << '\n';
		else std::cout << 0 << '\n';
	}
}