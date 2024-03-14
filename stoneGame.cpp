#include <iostream>

int main() {
	int stones;
	scanf_s("%d", &stones);
	if (stones % 2) printf("SK\n");
	else printf("CY\n");
}