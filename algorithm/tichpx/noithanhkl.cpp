#include<bits/stdc++.h>
using namespace std;

int main(){
	long n, x, res = 0;
	cin>>n;
	priority_queue<long, vector<long>, greater<long>> Q;
	for(int i=0, x; i<n; i++) {cin>>x; Q.push(x);}
	while(Q.size()>1){
		x = Q.top(); Q.pop();
		x += Q.top(); Q.pop();
		res += x;
		Q.push(x);
	}
	cout<<res;
}

