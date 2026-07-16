#include <stdio.h>

struct Item {
    int value, weight;
    float ratio;
};

int main() {
    int n, capacity;
    printf("Enter number of items and Knapsack capacity: ");
    scanf("%d %d", &n, &capacity);
    struct Item items[n];

    printf("Enter value and weight for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    // Simple Bubble Sort by value/weight ratio descending
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    float totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remain = capacity - currentWeight;
            totalValue += items[i].value * ((float)remain / items[i].weight);
            break;
        }
    }

    printf("Maximum value in Knapsack = %.2f\n", totalValue);
    return 0;
}