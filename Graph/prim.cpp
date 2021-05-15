#include <iostream>
#include <cstring>

#define MAXV 500
using namespace std;
typedef struct {
    int edges[MAXV][MAXV];
    int nedges, nvertices;
} Graph;
int findMinDistanceFromSourceVertex(Graph *g, bool inMST[], int distance[]) {
    int min = INT16_MAX, min_index;
    for (int i = 0; i < g->nvertices; i++)
    {
        if(!inMST[i] && distance[i] <= min) {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
    
}
void prim(Graph *g, int start) {
    int distance[g->nvertices], parent[g->nvertices];
    bool inMST[g->nvertices];

    memset(distance, 30000, sizeof(distance));
    memset(parent, -1, sizeof(parent));
    memset(inMST, false, sizeof(inMST));
    
    distance[start] = 0;
    parent[start] = -1;


    for (int i = 0; i < g->nvertices; i++)
    {
        int u = findMinDistanceFromSourceVertex(g, inMST, distance);
        distance[u] = 30000;
        inMST[u] = true;
        for (int v = 0; v < g->nvertices; v++)
        {
            if (!inMST[v] && g->edges[u][v] != 0 && g->edges[u][v] < distance[v])
            {
                distance[v] = g->edges[u][v];
                parent[v] = u;
            }
            
        }
        
    }

    for (int i = 1; i < g->nvertices; i++)
    {
        cout << parent[i] << "-" << i << " " << g->edges[i][parent[i]] << endl;
    }
    
}
int main() {
    Graph g;
    cin >> g.nvertices >> g.nedges;
    for (int i = 0; i < g.nedges; i++)
    {
        int start, finish, distance;
        cin >> start >> finish >> distance;
        g.edges[start][finish] = distance;
        g.edges[finish][start] = distance;
    }

    int startVertex;
    cin >> startVertex;
    prim(&g, startVertex);
    
}