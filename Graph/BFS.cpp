// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
#define MAXV 500
typedef struct
{
    int edges[MAXV][MAXV];
    int degrees[MAXV];
    bool visited[MAXV];
    int nedges, nvertices;
} Graph;
using namespace std;
void BFS(Graph *g, int start) {
    queue<int> Queue;
    int visited[g->nvertices];
    Queue.push(start);
    visited[start] = 1;
    while(!Queue.empty()) {
        for(int i=0; i<g->nvertices; i++) {
            if(g->edges[Queue.front()][i] == 1 && visited[i] != 1) {
                Queue.push(i);
                visited[i] = 1;
            }
        }
        cout << Queue.front() << " -> ";
        Queue.pop();
        
    }
    cout << "END" << endl;
    
}
int main() {
    // Write C++ code here
    Graph g;
    cin >> g.nvertices >> g.nedges;
    for (int i = 0; i < g.nedges; i++)
    {
        int start, finish;
        cin >> start >> finish;
        g.edges[start][finish] = 1;
    }
    BFS(&g, 0);

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
