#include <iostream>
#include <cmath>

int main() {
	int subjects;
	int credits = 0, in;
	double totalGpa = 0.0, gpa;
	char str[101];
	char markA, markOp;
	scanf_s("%d", &subjects);
	for (int i = 0; i < subjects; ++i) {
		scanf_s("%s %d %c %c", str, 101, &in, &markA, 1, &markOp, 1);
		credits += in;
		switch (markA) {
		case 'A': { gpa = 4.0; break; }
		case 'B': { gpa = 3.0; break; }
		case 'C': { gpa = 2.0; break; }
		case 'D': { gpa = 1.0; break; }
		case 'F': { continue; }
		}
		switch (markOp) {
		case '+': { gpa += 0.3; break; }
		case '-': { gpa -= 0.3; break; }
		}
		totalGpa += (gpa * in);
	}
	totalGpa /= credits;
	credits = totalGpa * 1000;
	if (credits % 10 >= 5) credits += 10 - (credits % 10);
	totalGpa = (double)credits / 1000;
	printf("%.2lf", totalGpa);
}
