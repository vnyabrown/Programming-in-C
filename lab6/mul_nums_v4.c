#include <stdio.h>

#define N 100

void longAddition(int num1[], int num2[], int size1, int size2) {
    int result[N];
    int carry = 0;
    int maxSize = (size1 > size2) ? size1 : size2;

    for (int i = 0; i < maxSize; i++) {
        int sum = carry;

        if (i < size1) {
            sum += num1[i];
        }

        if (i < size2) {
            sum += num2[i];
        }

        result[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0) {
        result[maxSize] = carry;
        maxSize++;
    }

    printf("Result: ");
    for (int i = maxSize - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}


