#include <iostream>

int main() {
    int N;
    scanf("%d", &N);
    int* staircase = new int[N];
    int* maxScores = new int[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &staircase[i]);
    }
    maxScores[0] = staircase[0];
    if (N > 1) {
        maxScores[1] = staircase[0] + staircase[1];
    }
    if (N > 2) {
        if (staircase[1] + staircase[2] > staircase[0] + staircase[2]) {
            maxScores[2] = staircase[1] + staircase[2];
        }
        else {
            maxScores[2] = staircase[0] + staircase[2];
        }
    }
    for (int i = 3; i < N; ++i) {
        if (maxScores[i-2] > maxScores[i-3] + staircase[i-1]) {
            maxScores[i] = maxScores[i-2] + staircase[i];
        }
        else {
            maxScores[i] = maxScores[i-3] + staircase[i] + staircase[i-1];
        }
    }
    printf("%d\n", maxScores[N-1]);
    delete maxScores;
    delete staircase;
}