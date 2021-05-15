#include <iostream>
using namespace std;
#define MAXV 500
typedef struct
{
    int edges[MAXV][MAXV];
    int degrees[MAXV];
    bool visited[MAXV];
    int nedges, nvertices;
} Graph;

void DFS(Graph *g, int v)
{
    g->visited[v] = true;
    cout << v << " ";
    for (int i = 0; i < g->nvertices; i++)
    {
        if(g->edges[v][i] == 1 && !g->visited[i]) {
            DFS(g, i);
        }
    }
    
    
}

int main()
{
    Graph g;
    cin >> g.nvertices >> g.nedges;

    for (int j = 0; j < g.nedges; j++)
    {
        int start, finish;
        cin >> start >> finish;
        g.edges[start][finish] = 1;
    }
    for (int i = 0; i < g.nvertices; i++)
    {
        for (int j = 0; j < g.nvertices; j++)
        {
            cout << g.edges[i][j] << " ";
        }
        cout << endl;
        
    }
    
    DFS(&g, 2);
    cout << endl;
}