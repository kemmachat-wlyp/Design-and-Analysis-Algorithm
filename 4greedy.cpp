#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
vector<int> v;
float round(float sum) {

	float value = (int)(sum * 100);
	return (float)value / 100;
}
int main() {
	int n , a ;
	double sum = 0;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	for(int i=0; i< v.size(); i++) {
		for(int j=0; j<=i; j++) {
			sum+=v[j];
		}
	}
	sum = sum /n;

	cout << round(sum);


}
