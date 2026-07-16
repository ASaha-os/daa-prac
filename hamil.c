#include <stdio.h>
#include <stdbool.h>
#define MAX 10

int graph[MAX][MAX], path[MAX];

bool isSafe(int v, int n, int pos) {
    if (graph[path[pos - 1]][v] == 0) return false;
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) return false;
    }
    return true;
}

bool hamCycleUtil(int n, int pos) {
    if (pos == n) {
        if (graph[path[pos - 1]][path[0]] == 1) return true;
        else return false;
    }

    for (int v = 1; v < n; v++) {
        if (isSafe(v, n, pos)) {
            path[pos] = v;
            if (hamCycleUtil(n, pos + 1)) return true;
            path[pos] = -1; // Backtrack
        }
    }
    return false;
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter Adjacency Matrix (0 or 1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++) path[i] = -1;
    path[0] = 0; // Start at vertex 0

    if (hamCycleUtil(n, 1)) {
        printf("Hamiltonian Cycle exists: ");
        for (int i = 0; i < n; i++) printf("%d -> ", path[i]);
        printf("%d\n", path[0]);
    } else {
        printf("No Hamiltonian Cycle exists.\n");
    }
    return 0;
}