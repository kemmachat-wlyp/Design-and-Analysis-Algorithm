#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

int Graph[1001][1001] = {{0}};
bool visited[1001] = {false};
int sasom_min[1001] = {0};
int n_v = 0;

void Prim(int start){
	
	vector<int> q;
	q.push_back(start);
    visited[start] = true;
	while(true){
    	int max = 0;
    	int source = -1;
    	int dest = -1;
    	for(int k=0;k<q.size();k++){
    		for(int i=0;i<n_v;i++){
    			if(!visited[i] && Graph[q[k]][i] > max){
    				max = Graph[q[k]][i];
    				source = q[k];
    				dest = i;		
				}		
			}
		}
		if(source!=-1){		
			q.push_back(dest);
			visited[dest] = true;	
			//cout << source << " " << dest << endl;		
			if(sasom_min[source] < max && source != start){
				sasom_min[dest] = sasom_min[source];
			}
			else{
				sasom_min[dest] = max;
			}
		}
    	else{
    		break;
		}
	}
}

int main(){
	
	int E;
	cin >> n_v >> E;
	n_v++;

	for(int i=0;i<E;i++){	
		int v1,v2,d;	
		cin >> v1 >> v2 >> d;	
		d--;	
		Graph[v1][v2] = d;
		Graph[v2][v1] = d;
	}
	int start,end,people;
	cin >> start >> end >> people;
	Prim(start);
	double ans = (double)people/sasom_min[end];
	cout << ceil(ans) << endl;
}


/*

7 10
1 2 30
1 3 15
1 4 10
2 4 25
2 5 60
3 4 40
3 6 20
4 7 35
5 7 20
6 7 30
1 7 99

*/
