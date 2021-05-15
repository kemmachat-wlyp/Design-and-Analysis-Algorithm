#include <iostream>
#include <cstring>

#define MAXV 500
using namespace std;
typedef struct {
    int edges[MAXV][MAXV];
    int nedges, nvertices;
} Graph;
int findMinDistanceFromSourceVertex(Graph *g, bool visited[], int distance[]) {
    int min = INT16_MAX, min_index;
    for (int i = 0; i < g->nvertices; i++)
    {
        if(!visited[i] && distance[i] <= min) {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
    
}
void dijkstra(Graph *g, int startVertex) {
    bool visited[g->nvertices];
    memset(visited, false, sizeof(visited));
    
    int distance[g->nvertices];
    memset(distance, 30000, sizeof(distance));

    distance[startVertex] = 0;
    for (int i = 0; i < g->nvertices; i++)
    {
        int u = findMinDistanceFromSourceVertex(g, visited, distance);
        cout << u << endl;
        visited[u] = true;
        for (int v = 0; v < g->nvertices; v++)
        {
            if(!visited[v] && g->edges[u][v] != 0 && g->edges[u][v] + distance[u] < distance[v]) {
                distance[v] = g->edges[u][v] + distance[u];
            }
        }
        
    }
    cout << "Vertex\t\tDistance\n========================"  << endl;
    for (int i = 0; i < g->nvertices; i++)
    {
        cout << i << "\t\t" << distance[i] << endl;
    }

    
    

}
int main() {
    Graph g;
    // cin >> g.nvertices >> g.nedges;
    // for (int i = 0; i < g.nedges; i++)
    // {
    //     int start, finish, distance;
    //     cin >> start >> finish >> distance;
    //     g.edges[start][finish] = distance;
    // }
    g.nvertices = 6;
    g.nedges = 8;
    g.edges[0][1] = 10;
    g.edges[0][2] = 15;
    g.edges[1][3] = 12;
    g.edges[1][4] = 15;
    g.edges[3][4] = 1;
    g.edges[3][5] = 2;
    g.edges[4][5] = 5;
    g.edges[2][5] = 10;
    int startVertex = 0;
    // cin >> startVertex;
    dijkstra(&g, startVertex);
    
}