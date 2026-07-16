#include <stdio.h>
#define INF 9999

struct Edge {
    int u, v, w;
};

int main() {
    int V, E, src;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    struct Edge edges[E];
    int dist[V];

    printf("Enter source, destination, and weight for each edge:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    printf("Enter source vertex index: ");
    scanf("%d", &src);

    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;

    // Relax all edges V - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    int hasCycle = 0;
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            hasCycle = 1;
            break;
        }
    }

    if (hasCycle) {
        printf("Graph contains negative weight cycle!\n");
    } else {
        printf("Vertex Distance from Source:\n");
        for (int i = 0; i < V; i++) printf("%d \t\t %d\n", i, dist[i]);
    }
    return 0;
}