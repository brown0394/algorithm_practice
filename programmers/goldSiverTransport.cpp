#include <string>
#include <vector>
#include <limits>

using namespace std;
bool calcTour(int a, int b, vector<int>& g, vector<int>& s, vector<int>& w, vector<int>& t, long long time) {
    long long tours, goldArrived, silverArrived, carry, goldMax, silverMax;
    goldArrived = 0;
    silverArrived = 0;
    goldMax = 0;
    silverMax = 0;
    carry = 0;
    for (int i = 0; i < g.size(); ++i) {
        tours = time / t[i];
        if (tours % 2) {
            ++tours;
        }
        tours = tours >> 1;
        if (tours >= g[i] + s[i]) {
            carry += g[i] + s[i];
            silverMax += s[i];
            goldMax += g[i];
        }
        else {
            tours = tours * w[i];
            if (tours >= g[i] + s[i]) {
                carry += g[i] + s[i];
                silverMax += s[i];
                goldMax += g[i];
            }
            else {
                carry += tours;
                goldMax += tours >= g[i] ? g[i] : tours;
                silverMax += tours >= s[i] ? s[i] : tours;
            }
        }
    }
    if (carry >= a + b && goldMax >= a && silverMax >= b) return true;
    return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = std::numeric_limits<long long>::max();
    long long last = 0;
    long long half;
    bool bigger;
    half = answer >> 1;
    while (last <= answer) {
        bigger = calcTour(a, b, g, s, w, t, half);
        if (bigger) {
            answer = half - 1;
        }
        else {
            last = half + 1;
        }
        half = last + ((answer - last) >> 1);
    }
    

    return last;
}