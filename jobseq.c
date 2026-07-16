#include <stdio.h>

struct Job {
    char id;
    int deadline, profit;
};

int main() {
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    struct Job jobs[n];

    printf("Enter Job ID (char), Deadline, and Profit:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    // Sort jobs descending by profit
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                struct Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }

    // Find max deadline to size the timeline slots
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) maxDeadline = jobs[i].deadline;
    }

    char result[maxDeadline];
    int slot[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) slot[i] = 0; // Initialize slots as free

    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        // Try to allocate slot from its last possible deadline back to 0
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                result[j] = jobs[i].id;
                slot[j] = 1;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Scheduled Job Sequence: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i]) printf("%c ", result[i]);
    }
    printf("\nTotal Profit: %d\n", totalProfit);
    return 0;
}