#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compareDeeper(vector<string>& words, int start, int end, int depth) {
    if (end <= start) return 0;
    if (words[start].size() == depth) {
        return depth + compareDeeper(words, start + 1, end, depth + 1);
    }
    if (end - start == 1) {
        return depth;
    }
    int include = start + 1;
    int sum = 0;
    while (include <= end) {
        while (include < end && words[start][depth] == words[include][depth]) { ++include; }
        sum += compareDeeper(words, start, include, depth + 1);
        start = include++;
    }

    return sum;
}

int solution(vector<string> words) {
    int answer = 0;
    std::sort(words.begin(), words.end());
    int include = 0;
    for (int i = 0, end = words.size(); i < end; ++i) {
        include = i + 1;
        while (include < end && words[i][0] == words[include][0]) { ++include; }
        printf("%d %d\n", i, include);
        answer += compareDeeper(words, i, include, 1);
        i = include - 1;
    }
    return answer;
}