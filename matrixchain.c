#include <stdio.h>
#define INF 9999999

int main() {
    int n;
    printf("Enter number of matrices + 1 (size of dimensions array): ");
    scanf("%d", &n);
    int p[n];
    printf("Enter the dimensions array:\n");
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);

    int m[n][n];
    for (int i = 1; i < n; i++) m[i][i] = 0;

    // L is chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INF;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) m[i][j] = q;
            }
        }
    }

    printf("Minimum number of multiplications is %d\n", m[1][n - 1]);
    return 0;
}