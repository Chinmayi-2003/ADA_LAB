#include <stdio.h>
#define MAX 10
int x[MAX];

int place(int k) {
    int i;
    for (i = 1; i < k; i++) {
        if (x[i] == x[k] || i - x[i] == k - x[k] || i + x[i] == k + x[k]) {
            return 0;
        }
    }
    return 1;
}

void write(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == x[i])
                printf("Q%d\t",i);
            else
                printf("-\t");
        }
        printf("\n");
    }
    printf("\n\n");
}

void nqueens(int n) {
    int k = 1;
    x[k] = 0;

    while (k != 0) {
        x[k] = x[k] + 1;

        while (x[k] <= n && !place(k)) {
            x[k] = x[k] + 1;
        }

        if (x[k] <= n) {
            if (k == n) {
                write(n);
            } else {
                k = k + 1;
                x[k] = 0;
            }
        } else {
            k = k - 1;
        }
    }
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    nqueens(n);
    return 0;
}
