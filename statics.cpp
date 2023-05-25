#include <iostream>
#include <algorithm>
#include <vector>

int getMean(int sum, int n) {
    float mean = sum / static_cast<float>(n);
    sum = static_cast<int>(mean);

    if (mean > 0) {
        if (mean - sum >= 0.5f) {
            return sum+1;
        }
    }
    else {
        if (mean - sum <= -0.5f) {
            return sum-1;
        }
    }


    return sum;
}

void recordFreq(int count, int last, std::vector<std::pair<int, int>>&freq, int& lastFreq) {
    if (count > freq[0].second) {
        freq[0].first = last;
        freq[0].second = count;
    }
    else if (count == freq[0].second && lastFreq < freq[0].second) {
        lastFreq = count;
        freq[1].first = last;
        freq[1].second = count;
    }
}

int getMostFreq(int* arr, int size) {
    std::vector<std::pair<int, int>> freq(2);
    int last = arr[0];
    int count = 0, lastFreq = 0;
    freq[0] = {0, 0};
    freq[1] = {0, 0};
    for (int i = 0; i < size; ++i) {
        if (arr[i] == last) {
            ++count;
        }
        else {
            recordFreq(count, last, freq, lastFreq);
            last = arr[i];
            count = 1;
        }
    }
    recordFreq(count, last, freq, lastFreq);
    if (freq[0].second != freq[1].second) {
        return freq[0].first;
    }
    return freq[1].first;
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = new int[n];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    sum = getMean(sum, n);
    

    std::sort(arr, arr+n);
    int range = arr[n-1] - arr[0];
    int freq = getMostFreq(arr, n);
    printf("%d\n%d\n%d\n%d", sum, arr[(n >> 1)], freq, range);

    delete[] arr;
}