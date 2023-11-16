#include <iostream>
#include <cmath>

int threeStarCount(unsigned int floor, unsigned int plus, unsigned int n) {
    unsigned int subFloor = floor;
    unsigned int subCeil;
    unsigned int answer = 0;
    unsigned int between = 0;
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

unsigned int threeStarCount(unsigned int floor, unsigned int plus, unsigned int n, unsigned int left,
    unsigned int leftAdded, unsigned int subDone) {
    unsigned int subFloor = floor;
    unsigned int subCeil;
    unsigned int answer = 0;
    unsigned int between = 0;
    unsigned int subPlus = plus;
    while (subFloor <= n) {
        subCeil = subFloor + ((subPlus - 2) << 1);
        if (subCeil >= n) {
            if ((subCeil - n) % 2 == 0) {
                ++answer;
            }
        }
        if (subPlus > 4) {
            --subPlus;
            ++between;
        }
        else {
            if (left << 1 == leftAdded) break;
            ++leftAdded;
            ++subDone;
            --plus;
            subPlus = plus;
            between = 0;
        }
        subFloor = (((subDone * 3) + between) * 9) + subPlus;
    }
    return answer;
}

unsigned int twoStarCount(unsigned int floor, unsigned int plus, unsigned int n, unsigned int subDone) {
    unsigned int subFloor = floor;
    unsigned int subCeil;
    unsigned int answer = 0;
    unsigned int between = 0;
    unsigned int subPlus = plus;
    while (subFloor <= n) {
        subCeil = subFloor + ((subPlus - 2) << 1);
        if (subCeil >= n) {
            if ((subCeil - n) % 2 == 0) {
                ++answer;
            }
        }
        if (subPlus > 4) {
            --subPlus;
            ++between;
        }
        else break;
        subFloor = ((subDone + between) * 9) + subPlus;
    }
    return answer;
}

unsigned int searchSubSpace(unsigned int n, unsigned int right, unsigned int left, unsigned int leftAdded,
    unsigned int subDone, unsigned int plus) {
    if (right <= 3) {
        switch (right) {
        case 0:
        case 1: {
            subDone = (subDone - 1) * 3;
            unsigned int subCeil = subDone + plus + 1 + ((plus - 1) << 1);
            if (subCeil >= n) {
                if ((subCeil - n) % 2 == 0) {
                    return 1;
                }
            }
            return 0;
        }
        case 2: { return twoStarCount(subDone * std::pow(3, right) + plus, plus, n, subDone); }
        case 3: { return threeStarCount(subDone * std::pow(3, right) + plus, plus, n, left, leftAdded, subDone); }
        }        
    }
    unsigned int answer = 0;
    unsigned int subLeft = right - 2;
    unsigned int subRight = 2;
    unsigned int subFloor = subDone * std::pow(3, right) + plus;
    unsigned int subCeil = subFloor + ((plus - 2) << 1);
    while (subFloor <= n) {
        if (subCeil >= n) {
            answer += searchSubSpace(n, subRight - 1, left + subLeft + 1, leftAdded + 1, subDone * std::pow(3, subLeft + 1) + 1, plus - 1);
        }
        if (!subLeft) {
            if (left << 1 == leftAdded) break;
            ++leftAdded;
            ++subDone;
            --plus;
            subLeft = right - 1;
            subRight = 1;
            subFloor = subDone * std::pow(3, right) + plus;
            subCeil = subFloor + ((plus - 2) << 1);
        }
        else {
            subFloor =  (((subDone * std::pow(3, subLeft)) + 1) * std::pow(3, subRight)) + plus - 1;
            subCeil = subDone * std::pow(3, subLeft) + ((left + subLeft) << 1) - leftAdded;
            for (int i = 0; i < subRight; ++i) {
                subCeil = (subCeil * 3) + 2;
            }
        }
        --subLeft;
        ++subRight;
    }
    return answer;
}

unsigned int solution(unsigned int n) {
    unsigned int answer = 0;
    unsigned int tripleCount = 2;
    unsigned int floor = std::pow(3, tripleCount) + (tripleCount << 1);
    unsigned int ceil = (5 * 3) + 2;
    if (n == 5) return 1;
    while (floor <= n) {
        if (ceil >= n) {
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
            unsigned int left = tripleCount - 2;
            unsigned int right = 2;
            unsigned int subFloor, subCeil;
            unsigned int plus = tripleCount << 1;
            subFloor = floor;
            subCeil = subFloor + ((plus - 2) << 1);
            while (true) {
                if (subFloor <= n) {
                    if (subCeil >= n) {
                        answer += searchSubSpace(n, right - 1, left + 1, 1, (std::pow(3, left + 1) + 1), plus - 1);                      
                    }
                }
                else {
                    break;
                }
                if (!left) break;
                subFloor = ((std::pow(3, left) + 1) * std::pow(3, right)) + plus - 1;
                subCeil = (std::pow(3, left) + (left << 1));
                for (int i = 0; i < right; ++i) {
                    subCeil = (subCeil * 3) + 2;
                }
                --left;
                ++right;
            }
            break;
        }
        ++tripleCount;
        ceil = (ceil * 3) + 2;
        floor = std::pow(3, tripleCount) + (tripleCount << 1);
    }
    return answer;
}
int main() {
    unsigned int n;
    std::cin >> n;
    printf("%d\n", solution(n));
}