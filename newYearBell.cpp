#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

struct hearingInfo {
    int idx;
    int count;
    bool operator < (const hearingInfo& other) {
        if (count == other.count) return idx < other.idx;
        return count < other.count;
    }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int participants, bellStrikes;
    std::cin >> participants >> bellStrikes;
    std::vector<std::bitset<205>> hearings(participants);
    std::vector<hearingInfo> infos(participants);
    for (int i = 0, in; i < participants; ++i) {
        infos[i].idx = i;
        for (int j = 0; j < bellStrikes; ++j) {
            std::cin >> in;
            if (in) {
                hearings[i][j] = true;
                ++infos[i].count;
            }
        }
    }
    std::sort(infos.begin(), infos.end());
    int a = 10;
    for (int i = 0, til = infos.size() - 1; i < til; ++i) {
        int closer = infos[i].idx;
        int further = infos[i + 1].idx;
        for (int j = 0; j < bellStrikes; ++j) {
            if (hearings[closer][j] && !hearings[further][j]) {
                std::cout << "NO\n";
                return 0;
            }
        }
    }
    std::cout << "YES\n";
}