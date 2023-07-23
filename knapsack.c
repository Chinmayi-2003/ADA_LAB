#include <stdio.h>
#include <stdbool.h>

int p[15],w[15],maxW;
void main(){
    int n,i,j,maxP;
    printf("Enter the number of items\n");
    scanf("%d",&n);
    printf("Enter the max weight\n");
    scanf("%d",&maxW);
    printf("Enter the weights\n");
    for(i=0;i<n;i++)
    scanf("%d",&w[i]);
    printf("Enter the profits\n");
    for(i=0;i<n;i++)
    scanf("%d",&p[i]);
    maxP=knapsack(n);
    printf("Optimal profit is %d ",maxP);
}



int knapsack(int n) {
    int v[n+1][maxW+1],i,j;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= maxW; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (w[i-1] <= j)
                v[i][j] = max(p[i - 1] + v[i - 1][j - w[i - 1]], v[i - 1][j]);
            else
                v[i][j] = v[i - 1][j];
        }
    }

    int selected[n];
    i = n; j = maxW;
    int count = 0;

    while (i > 0 && j > 0) {
        if (v[i][j] != v[i - 1][j]) {
            selected[count++] = i;
            j -= w[i - 1];
            i--;
        } else {
            i--;
        }
    }

    printf("TABLE \n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= maxW; j++) {
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }

    printf("Selected objects: ");
    for (int j = count - 1; j >= 0; j--)
        printf("%d ", selected[j]);
    printf("\n");

    return v[n][maxW];
}



int max(int a, int b) {
    return (a > b) ? a : b;
}
