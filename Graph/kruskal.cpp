// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
#define MAXV 500
typedef struct
{
    int edges[MAXV][MAXV];
    int degrees[MAXV];
    bool visited[MAXV];
    int nedges, nvertices;
} Graph;
typedef struct 
{
    int start;
    int finish;
    int distance;
} Vertex;
using namespace std;
bool comparator(Vertex v1, Vertex v2) {
    return v1.distance < v2.distance;
}
bool isCycle(Graph *g, int start, int finish) {
    for(int i=0; i<g->nvertices; i++) {
        
    }
}
void kruskal(Graph *g) {
    Vertex v[g->nedges];
    int count = 0;
    for(int i=0; i<g->nvertices; i++) {
        for(int j=0; j<g->nvertices; j++) {
            if(g->edges[i][j] > 0) {
                v[count].start = i;
                v[count].finish = j;
                v[count].distance = g->edges[i][j];
                g->edges[j][i] = -1;
                count++;
            }
        }
    }
    sort(v, v+count, comparator);
    cout << endl;
    int visited[g->nvertices];
     for(int i=0; i<count; i++) {

        if(!isCycle(g, v[i].start, v[i].finish)) {
            g->edges[v[i].start][v[i].finish] = v[i].distance;
            g->edges[v[i].finish][v[i].start] = v[i].distance;
        }
    }   
    for(int i=0; i<g->nvertices; i++) {
        for(int j=0; j<g->nvertices; j++) {
            if(g->edges[i][j] > 0) {
                cout << i << "-" << j << " = " << g->edges[i][j] << endl;
                g->edges[j][i] = 0;
            }
        }
        
    }
    
    
}
int main() {
    // Write C++ code here
    Graph g;
    cin >> g.nvertices >> g.nedges;
    for (int i = 0; i < g.nedges; i++)
    {
        int start, finish, distance;
        cin >> start >> finish >> distance;
        g.edges[start][finish] = distance;
        g.edges[finish][start] = distance;
    }
    kruskal(&g);

    return 0;
}
// 8 9
// 0 1
// 1 2
// 1 6
// 2 6
// 4 2
// 5 1
// 5 3
// 6 7
// 7 5
