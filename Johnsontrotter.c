#include<stdio.h>
#define LtoR 0
#define RtoL 1

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main(){
    int n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("The %d permutations are \n",fact(n));
    permutation(n);
}
int fact(int n) {
    int factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial = factorial * i;
    }
    return factorial;
}

int searchArray(int arr[], int n, int mob) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == mob) {
            return i + 1;
        }
    }
    return -1;
}
int getMobileComp(int a[], int dir[], int n) {
    int prevMob = 0, mob = 0;
    for (int i = 0; i < n; i++) {
        if (dir[a[i] - 1] == RtoL && i != 0) {
            if (a[i] > a[i - 1] && a[i] > prevMob) {
                mob = a[i];
                prevMob = mob;
            }
        }

        if (dir[a[i] - 1] == LtoR && i != n - 1) {
            if (a[i] > a[i + 1] && a[i] > prevMob) {
                mob = a[i];
                prevMob = mob;
            }
        }
    }

    if (mob == 0 && prevMob == 0) {
        return 0;
    } else {
        return mob;
    }
}

void printOnePerm(int arr[], int dir[], int n, int pnum) {
    int mob = getMobileComp(arr, dir, n);
    int pos = searchArray(arr, n, mob);

    if (dir[arr[pos - 1] - 1] == RtoL) {
        swap(&arr[pos - 1], &arr[pos - 2]);
    } else if (dir[arr[pos - 1] - 1] == LtoR) {
        swap(&arr[pos], &arr[pos - 1]);
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > mob) {
            if (dir[arr[i] - 1] == LtoR) {
                dir[arr[i] - 1] = RtoL;
            } else if (dir[arr[i] - 1] == RtoL) {
                dir[arr[i] - 1] = LtoR;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf(" %d ",arr[i]);
    }
    printf("\n");
}


void permutation(int n){
    int arr[n];
    int dir[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
        printf(" %d ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        dir[i] = RtoL;
    }

    for (int i = 1; i < fact(n); i++) {
        printOnePerm(arr, dir, n,i);
    }
}
