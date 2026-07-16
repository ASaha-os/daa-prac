#include <stdio.h>
#define INF 9999
#define MAX 10

void dijkstra(int cost[MAX][MAX], int n, int start) {
    int distance[MAX], visited[MAX], count, mindistance, nextnode;
    
    for (int i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        visited[i] = 0;
    }
    
    distance[start] = 0;
    visited[start] = 1;
    count = 1;
    
    while (count < n - 1) {
        mindistance = INF;
        for (int i = 0; i < n; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }
        
        visited[nextnode] = 1;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                }
            }
        }
        count++;
    }

    printf("\nShortest distances from source node %d:\n", start);
    for (int i = 0; i < n; i++) {
        printf("To node %d: %d\n", i, distance[i]);
    }
}

int main() {
    int n, start, cost[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost adjacency matrix (Use 9999 for Infinity):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    printf("Enter starting node index (0 to %d): ", n - 1);
    scanf("%d", &start);
    dijkstra(cost, n, start);
    return 0;
}