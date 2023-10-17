#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

struct info {
    int g;
    int s;
    int w;
    int t;
};

bool sortstd(info& one, info& two) {
    if (one.t == two.t) {
        return one.w > two.w;
    }
    return one.t < two.t;
}

void calcTour(list<info>& arr, int a, int b, long long& answer, long long& last) {
    int tours, goldArrived, silverArrived, carry;
    while (true) {
        last = answer;
        if (answer == 0) answer = 1;
        answer = answer << 1;
        goldArrived = 0;
        silverArrived = 0;
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            tours = answer / (*it).t;
            if (tours % 2) {
                ++tours;
            }
            tours = tours >> 1;
            carry = tours * (*it).w;
            if (goldArrived == a && silverArrived == b && carry) {
                return;
            }
            if ((*it).g && goldArrived < a) {
                if (carry >= (*it).g) {
                    if (goldArrived + (*it).g < a) {
                        goldArrived += (*it).g;
                        carry -= (*it).g;
                    }
                    else {
                        carry -= (a - goldArrived);
                        goldArrived += (a - goldArrived);
                    }
                }
                else {
                    if (goldArrived + carry < a) {
                        goldArrived += carry;
                        carry = 0;
                    }
                    else {
                        carry -= (a - goldArrived);
                        goldArrived += (a - goldArrived);
                    }
                }
            }
            if ((*it).s && carry && silverArrived < b) {
                if (carry >= (*it).s) {
                    if (silverArrived + carry > b) {
                        silverArrived = b;
                    }
                    else {
                        silverArrived += (*it).s;
                    }
                }
                else {
                    if (silverArrived + carry > b) {
                        silverArrived = b;
                    }
                    else {
                        silverArrived += carry;
                    }
                }
            }
        }
        if (silverArrived == b && goldArrived == a) return;
    }
}

bool calcTourOnce(list<info>& arr, int a, int b, long long time) {
    int tours, goldArrived, silverArrived, carry;
    goldArrived = 0;
    silverArrived = 0;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        tours = time / (*it).t;
        if (tours % 2) {
            ++tours;
        }
        tours = tours >> 1;
        carry = tours * (*it).w;
        if (goldArrived == a && silverArrived == b && carry) {
            return true;
        }
        if ((*it).g && goldArrived < a) {
            if (carry >= (*it).g) {
                if (goldArrived + (*it).g < a) {
                    goldArrived += (*it).g;
                    carry -= (*it).g;
                }
                else {
                    carry -= (a - goldArrived);
                    goldArrived += (a - goldArrived);
                }
            }
            else {
                if (goldArrived + carry < a) {
                    goldArrived += carry;
                    carry = 0;
                }
                else {
                    carry -= (a - goldArrived);
                    goldArrived += (a - goldArrived);
                }
            }
        }
        if ((*it).s && carry && silverArrived < b) {
            if (carry >= (*it).s) {
                if (silverArrived + carry > b) {
                    silverArrived = b;
                }
                else {
                    silverArrived += (*it).s;
                }
            }
            else {
                if (silverArrived + carry > b) {
                    silverArrived = b;
                }
                else {
                    silverArrived += carry;
                }
            }
        }
    }
    if (silverArrived == b && goldArrived == a) {
        return true;
    }
    return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    list<info> arr;
    for (int i = 0; i < g.size(); ++i) {
        arr.push_back({ g[i], s[i], w[i], t[i] });
    }
    long long answer = 0;
    long long last;
    calcTour(arr, a, b, answer, last);
    long long half;
    bool bigger;
    ++last; --answer;
    half = last + ((answer - last) >> 1);
    while (true) {
        bigger = calcTourOnce(arr, a, b, half);
        if (bigger) {
            answer = half - 1;
        }
        else {
            last = half + 1;
        }
        if (answer == last) {
            bigger = calcTourOnce(arr, a, b, answer);
            if (!bigger) ++answer;
            break;
        }
        half = last + ((answer - last) >> 1);
    }
    

    return answer;
}

int main() {
    vector<int> g{257};//{70, 70, 0};//{100};
    vector<int>s{0};//{0, 0, 500};//{100};
    vector<int>w{1};//{100, 100, 2};//{7};
    vector<int>t{1};//{4, 8, 1};//{10};
    long long a = 1;
    a = a >> 1;
    printf("%d\n", solution(257, 0, g, s, w, t));
}