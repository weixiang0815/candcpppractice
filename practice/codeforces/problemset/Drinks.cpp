#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	double p;
	double ans = 0.0;
	for(int i = 0; i < n; i++){
		cin >> p;
		ans += p;
	}
	cout << ans/(double)n;
	return 0;
}
