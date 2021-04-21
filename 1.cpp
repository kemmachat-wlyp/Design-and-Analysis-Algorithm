#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {
	int v,e;
	cin>>v>>e;
	int s = e*2;
	int sum = 0;
	int g[s];
	
	memset(g,0,sizeof(g));

	for(int i=0; i<s; i++) {
		cin>>g[i];
	}
	
	int* max = max_element(g,g+s);
	int* kept = new int[*max+1];
	
	for(int i=0; i<=*max; i++) {
		kept[i]= -1;
	}

	for(int i=0; i<s; i++) {
		if(kept[g[i]]==-1) {
			kept[g[i]] = g[i];
		}
	}
	
	for(int i=0; i<=*max; i++) {
		if((kept[i] % 2) == 0) {
			
			sum++;
		}
	}
	
	cout<< sum << endl;
	
	return 0 ;
}
