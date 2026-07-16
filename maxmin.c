#include <stdio.h>

// Brute Force Method
void maxMinBrute(int arr[], int n, int *max, int *min) {
    *max = arr[0];
    *min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > *max) *max = arr[i];
        if (arr[i] < *min) *min = arr[i];
    }
}

// Divide and Conquer Method
void maxMinDC(int arr[], int low, int high, int *max, int *min) {
    int max1, min1, max2, min2;
    if (low == high) {
        *max = arr[low];
        *min = arr[low];
    } else if (low == high - 1) {
        if (arr[low] < arr[high]) {
            *max = arr[high];
            *min = arr[low];
        } else {
            *max = arr[low];
            *min = arr[high];
        }
    } else {
        int mid = low + (high - low) / 2;
        maxMinDC(arr, low, mid, &max1, &min1);
        maxMinDC(arr, mid + 1, high, &max2, &min2);
        *max = (max1 > max2) ? max1 : max2;
        *min = (min1 < min2) ? min1 : min2;
    }
}

int main() {
    int n, max, min;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    maxMinBrute(arr, n, &max, &min);
    printf("[Brute Force] Max: %d, Min: %d\n", max, min);

    maxMinDC(arr, 0, n - 1, &max, &min);
    printf("[Divide & Conquer] Max: %d, Min: %d\n", max, min);
    return 0;
}