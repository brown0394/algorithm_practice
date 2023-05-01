#include <iostream>

int main() {
    int numOfCards;
    scanf("%d", &numOfCards);
    int* array = new int[numOfCards];

    int start = 1;
    int size = numOfCards - 1;
    int last = numOfCards - 1;
    for (int i = 0; i < numOfCards; ++i) {
        array[i] = i+1;
    }
    while (size) {
        last = (last + 1) % numOfCards;
        array[last] = array[start];
        start = (start + 2) % numOfCards;
        --size;
    }

    printf("%d\n", array[last]);

    delete[] array;
}