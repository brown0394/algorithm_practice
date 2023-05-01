#include <iostream>

int main() {
    int numOfCards;
    scanf("%d", &numOfCards);
    int size = numOfCards/2;
    int* array = new int[size];

    int val = 2;
    for (int i = 0; i < size; ++i) {
        array[i] = val;
        val += 2;
    }
    int extract = 1;
    int insert = 0;
    while (true) {
        array[insert++] = array[extract];
        extract += 2;
        if (extract >= size) {
            if (insert < 4) {
                if (insert == 3) {
                    printf("%d\n", array[2]);
                }
                else {
                    printf("%d\n", array[0]);
                }
                break;
            }
            size = insert;
            insert = 0;
            extract = 1;
        }
    }
    delete[] array;
}