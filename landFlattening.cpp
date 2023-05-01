#include <iostream>
#include <memory.h>
int main() {
    int x, y, b;
    scanf("%d %d %d", &x, &y, &b);
    int tot = x * y;
    int index[257];
    memset(index, -1, sizeof(index));
    int *numbs = new int[tot];
    int *numindx = new int[tot];
    int numbsidx = 0;
    int numindxidx = 0;
    int sum = 0;
    int time = 0;
    for(int i = 0; i < tot; ++i) {
        int temp;
        scanf("%d", &temp);
        sum += temp;
        if (index[temp] == -1) {
            index[temp] = numbsidx;
            numbs[numbsidx++] = 1;
            numindx[numindxidx++] = temp;
        }
        else {
            ++numbs[index[temp]];
        }
    }
    int avg = (int)((float)sum / tot);
    if (((float)sum / tot) - avg >= 0.5) {
        ++avg;
    }
    
    int dig = 0;
    int pile = 0;
    int lastDig = 0;
    int lastPile = 0;
    bool avgIncreased = false;
    while(true) {
        for(int i = 0; i < numindxidx; ++i) {
            if (numindx[i] < avg) {
                pile += ((avg - numindx[i]) * numbs[index[numindx[i]]]);
            }
            else if (numindx[i] > avg) {
                dig += ((numindx[i] - avg) * numbs[index[numindx[i]]]);
            }
        }
        if (b + dig < pile) {
            --avg;
            if (avgIncreased) {
                time = (lastDig * 2) + lastPile;
                break;
            }
        }
        else if (b + dig >= tot) {
            if (avgIncreased && ((dig * 2) + pile > lastPile + (lastDig * 2))) {
                time = (lastDig * 2) + lastPile;
                --avg;
                break;
            }
            lastPile = pile;
            lastDig = dig;
            avgIncreased = true;
            ++avg;//////
        }
        else {
            time = (dig * 2) + pile;
            break;
        }
        dig = 0;
        pile = 0;
    }
    printf("%d %d\n", time, avg);
    delete[] numbs;
    delete[] numindx;
}