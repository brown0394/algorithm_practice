#include <iostream>
#include <list>
#include <vector>

struct longest {
	int from, to;
};

std::vector<longest> longestOnes;
int longestSad = 0;
std::list<int> daysFlower;
std::vector<int> days;
int getDaysBought(int end, int start, std::list<int>::iterator it) {
	int sum = 0;
	int count = end - start;
	if (count > longestSad) {
		longestSad = count;
		longestOnes.clear();
		longestOnes.push_back({ start, end });
	}
	else if (count == longestSad) longestOnes.push_back({ start, end });
	count <<= 1;
	int til = start - count;
	while (count-- && it != daysFlower.end() && *it >= til) {
		it = daysFlower.erase(it);
		++sum;
	}
	return sum;
}

int main() {
	int size;
	scanf_s("%d", &size);
	if (size == 0) {
		printf("0\n");
		return 0;
	}
	days.resize(size);
	
	
	int start = -1;
	int sum = 0;
	std::list<int>::iterator flowerIt;
	for (int i = 0; i < size; ++i) {
		daysFlower.push_front(i);
		scanf_s("%d", &days[i]);
		if (days[i] < 0 && start < 0) {
			start = i;
			flowerIt = daysFlower.begin();
		}
		else if (days[i] >= 0 && start >= 0) {
			sum += getDaysBought(i, start, ++flowerIt);
			start = -1;
		}
	}
	if (start >= 0) {
		sum += getDaysBought(size, start, ++flowerIt);
	}
	auto dit = daysFlower.begin();
	auto dend = daysFlower.end();
	int additional = 0;
	if (dit != dend) {
		longestSad *= 3;
		for (auto it = longestOnes.rbegin(), end = longestOnes.rend(); it != end; ++it) {
			while (dit != dend && *dit >= it->from) ++dit;
			if (dit == dend) break;
			int included = 0;
			auto tempIt = dit;
			int til = it->from - longestSad;
			while (tempIt != dend && *tempIt >= til) {
				++tempIt;
				++included;
			}
			if (included > additional) additional = included;
		}
	}

	printf("%d\n", sum + additional);
}