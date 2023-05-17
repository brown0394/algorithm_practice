#include <iostream>

int main() {
    int n,k;
    scanf("%d %d", &n, &k);
    int arr[10][11];
    int ans;
    if (k == 0 || n == k) {
        ans = 1;
    }
    else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || i == j) {
                    arr[i][j] = 1;
                }
                else{
                    arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
                }
            }
        }
        ans = arr[n-1][k-1] + arr[n-1][k];
    }

    
    printf("%d\n", ans);
}