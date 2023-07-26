#include <iostream>
#include <cstring>


void multiply(char *operand1, char *operand2, char *result) {
    int num, carry = 0, calc;
    char *resultCur;
    for (char* n1 = operand1; *n1 != '\0'; ++n1) {
        resultCur = result++;
        for (char* n2 = operand2; *n2 != '\0'; ++n2) {
            if (*resultCur) {
                calc = (*n1 - '0') * (*n2 - '0') + carry + (*resultCur - '0');
            }
            else {
                calc = (*n1 - '0') * (*n2 - '0') + carry;
                *(resultCur+1) = 0;
            }
            if (calc > 9) {
                num = calc % 10;
                carry = (calc - num) / 10;
            }
            else {
                num = calc;
                carry = 0;
            }

            *resultCur = num + '0';
            ++resultCur;
        }
        if (carry) {
            *resultCur = carry + '0';
            *(resultCur+1) = 0;
            carry = 0;
        }
    }
}

void addOne(char* number) {
    bool carry = false;
    while (*number) {
        if (*number == '9') {
            *number = '0';
            carry = true;
        }
        else {
            *number += 1;
            carry = false;
            break;
        }
        ++number;
    }
    if (carry) {
        *number = '1';
        *(number + 1) = '\0';
    }
}

int main() {
    char num1[2000] = "42";
    char num2[2000] = "";
    char fnum[5] = "5";

    int N;
    scanf("%d", &N);
    if (N < 5) {
        printf("0\n");
    }
    else {
        char* n1 = num1;
        char* n2 = num2;
        for (int i = 5; i <= N; ++i) {
            n2[0] = '\0';
            multiply(n1, fnum, n2);
            addOne(fnum);
            n1 = n2;
            if (n2 == num2) {
              n2 = num1;  
            }
            else {
              n2 = num2;
            }
        }
        int count = 0;
        for (; *n1 <= '0'; ++n1) {
            ++count;
        }
        printf("%d\n", count);
    }
}