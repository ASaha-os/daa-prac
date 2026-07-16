#include <stdio.h>
#include <stdbool.h>
#define MAX 10

int graph[MAX][MAX], x[MAX]; // x holds color assignments

bool isSafe(int v, int n, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && c == x[i]) return false;
    }
    return true;
}

bool graphColoringUtil(int n, int m, int v) {
    if (v == n) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, n, c)) {
            x[v] = c;
            if (graphColoringUtil(n, m, v + 1)) return true;
            x[v] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter Adjacency Matrix (0 or 1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter number of colors: ");
    scanf("%d", &m);

    for (int i = 0; i < n; i++) x[i] = 0;

    if (graphColoringUtil(n, m, 0)) {
        printf("Solution exists. Assigned Colors are:\n");
        for (int i = 0; i < n; i++) printf("Vertex %d -> Color %d\n", i, x[i]);
    } else {
        printf("Solution does not exist with %d colors.\n", m);
    }
    return 0;
}