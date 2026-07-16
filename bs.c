#include <stdio.h>

// Iterative Binary Search
int binarySearchIterative(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target) return binarySearchRecursive(arr, mid + 1, high, target);
    return binarySearchRecursive(arr, low, mid - 1, target);
}

int main() {
    int n, target, choice, result;
    printf("Enter number of elements (sorted): ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    printf("Enter element to search: ");
    scanf("%d", &target);
    printf("Choose: 1. Iterative  2. Recursive: ");
    scanf("%d", &choice);

    if (choice == 1) result = binarySearchIterative(arr, n, target);
    else result = binarySearchRecursive(arr, 0, n - 1, target);

    if (result != -1) printf("Element found at index %d\n", result);
    else printf("Element not found\n");
    return 0;
}