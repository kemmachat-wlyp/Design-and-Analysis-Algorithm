#include<iostream>

using namespace std;

int wuhan[1001] = {0};
int zonee[1001][1001] = {{0}};

int main(){
	
	int zone,k;
	
	cin >> zone >> k;
	
	for(int i=0;i<zone;i++){
		int n;
		cin >> n;
		for(int j=0;j<n;j++){	
			int a;
			cin >> a;
			wuhan[a]++;
			zonee[i][a]++;			
		}	
	}
	
	int count = 0;
	
	for(int i=0;i<1001;i++){
		if(wuhan[i]>=k){
			count++;
		}
	}
	cout << count << endl;
	for(int i=0;i<1001;i++){
		if(wuhan[i]>=k){
			cout<< i << " ";
		}
	}
	cout << endl;
	for(int i=0;i<zone;i++){
		int sum = 0;
		for(int j=0;j<1001;j++){
			if(zonee[i][j]>0 && wuhan[j]>=k){
				sum++;
			}
		}
		cout << sum << " ";
	}
		
}





/*
5 3
5
12 387 15 162 5
6
14 162 92 387 7 748
4
14 5 12 387
6
17 952 12 92 398 849
5
14 5 92 12 387
*/
