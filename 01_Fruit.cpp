#include<iostream>
#include<algorithm>

using namespace std;


struct Fruit{
	int index = 0;
	int V = 0;
	int B = 0;
	int P=  0;
	
	Fruit(){}
	Fruit(int a,int b,int c,int d){
		index = a;
		V = b;
		B = c;
		P = d;
	}
};

bool check(Fruit a,Fruit b){
	
	double value1 =	((double)a.V/(a.B*a.P));
	double value2 = ((double)b.V/(b.B*b.P));
	
	if(value1==value2){
		return a.index < b.index;
	}
	else{
		return value1 > value2;
	}
	
}

Fruit answer[1001];
Fruit temp[1001];

int main(){
		
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		int v,b,p;
		cin >> v >> b >> p;
		Fruit f = Fruit(i,v,b,p);
		temp[i] = f;
	}
	
	sort(temp,temp+n,check);
	
	double w;
	
	cin >> w;
	
	w = w*1000;
	
	for(int i=0;i<n;i++){
		
		double temp_w = temp[i].B*temp[i].P;
		
		if(temp_w <= w){
			
			w -= temp_w;
			
			answer[temp[i].index].B = temp[i].B;	
		}
		else{	
			answer[temp[i].index].B = (int)w/temp[i].P;
			answer[temp[i].index].P = (int)w%temp[i].P;	
			break;
		}	
	}
	
	for(int i=0;i<n;i++){
		cout << answer[i].B << " " << answer[i].P << endl;
	}
	
}


/* test case

2
10000 200 5
5000 100 10
1.255



3
10000 200 5
5000  100 10
7000  100 7
1.951


3
100000 200 5
100000 100 10
70000 100  7
1.951

*/



