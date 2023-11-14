#include <iostream>
#include <cmath>
#include <vector>

struct star {
    int plus;
    int plusBackSide;
};

bool reArrangeStar(std::vector<star>& stars, int& rightside, int& between, int& idx, int right) {
    rightside += stars[right].plus - 1;
    between -= stars[right].plus - 1;
    stars[right].plus = 0;
    ++stars[idx].plus;
    bool looped = (stars[idx].plusBackSide + stars[idx].plus > (idx + 1) << 1);
    while (stars[idx].plusBackSide + stars[idx].plus > (idx + 1) << 1) {
        --stars[idx].plus;
        between -= stars[idx].plus;
        rightside += stars[idx].plus;
        ++stars[idx].plusBackSide;
        if (idx + 1 < right) {
            for (int i = idx + 1; i < right; ++i) {
                stars[i].plusBackSide -= stars[idx].plus;
            }
        }
        stars[idx].plus = 0;
        --idx;
        ++stars[idx].plus;
        if (idx == 0) {
            if (stars[0].plus > 2) return true;
            break;
        }
    }
    if (looped) {
        idx = right - 1;
    }
    return false;
}

int getFloor(std::vector<star>& stars, int rightside) {
    int subFloor = 1;
    for (int i = 0; i < stars.size() - 2; ++i) {
        subFloor *= 3;
        subFloor += stars[i].plus;
    }
    return (subFloor * 9) + rightside;
}

int threeStarCount(int floor, int plus, int n) {
    int subFloor = floor;
    int subCeil;
    int answer = 0;
    int between = 0;
    while (subFloor <= n) {
        subCeil = subFloor + ((plus - 2) << 1);
        if (subCeil >= n) {
            if ((subCeil - n) % 2 == 0) {
                ++answer;
            }
        }
        if (plus > 4) {
            --plus;
            ++between;
        }
        else break;
        subFloor = ((3 + between) * 9) + plus;
    }

    return answer;
}

int solution(int n) {
    int answer = 0;
    int tripleCount = 2;
    int floor = std::pow(3, tripleCount) + (tripleCount << 1);
    long long ceil = (5 * 3) + 2;
    if (n == 5) return 1;
    while (floor <= n) {
        if (ceil > n) {
            if (tripleCount < 3) {
                if ((ceil - n) % 2 == 0) {
                    ++answer;
                }
                break;
            }
            if (tripleCount < 4) {
                answer = threeStarCount(floor, tripleCount << 1, n);
                break;
            }
            int subFloor = floor;
            int plus = tripleCount << 1;
            std::vector<star> stars(tripleCount, star{0, 0});
            int right = tripleCount - 3;
            int idx = right-1;
            int subCeil, between = 0;
            int rightside = plus;
            while (subFloor <= n) {
                subCeil = subFloor + ((rightside - 2) << 1);
                if (subCeil >= n) {
                    if ((subCeil - n) % 2 == 0) {
                        ++answer;
                    }
                }
                if (rightside > 4) {
                    ++stars[right].plus;
                    --rightside;
                    ++between;
                }
                else {
                    if (reArrangeStar(stars, rightside, between, idx, right)) break;
                }
                subFloor = getFloor(stars, rightside);
                while (subFloor > n) {
                    if (reArrangeStar(stars, rightside, between, idx, right)) break;
                    subFloor = getFloor(stars, rightside);
                }
            }
        }
        ++tripleCount;
        ceil = (ceil * 3) + 2;
        floor = std::pow(3, tripleCount) + (tripleCount << 1);
    }
    return answer;
}
int main() {
    int n;
    std::cin >> n;
    printf("%d\n", solution(n));
}