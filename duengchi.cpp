#include <iostream>

typedef struct Node Node;

struct Node {
    int weight;
    int height;
    int rank;
};

int main() {
    int inputs;
    scanf("%d", &inputs);
    Node* figures = new Node[inputs];
    for (int i = 0; i < inputs; ++i) {
        scanf("%d %d", &figures[i].weight, &figures[i].height);
        figures[i].rank = 1;
    }
    for (int i = 0; i < inputs; ++i) {
        for (int j = 0; j < inputs; ++j) {
            if (figures[j].height > figures[i].height && figures[j].weight > figures[i].weight) {
                ++figures[i].rank;
            }
        }
    }
    for (int i = 0; i < inputs; ++i) {
        if (i > 0) putchar(' ');
        printf("%d", figures[i].rank);
    }
}