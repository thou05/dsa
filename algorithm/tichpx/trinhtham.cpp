#include<bits/stdc++.h>
using namespace std;

int main(){
	priority_queue<pair<int,int>> Q;
	int n,k,x;
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>x;
		Q.push({x,i});
		while(i-Q.top().second >= k) Q.pop();
		if(i >= k) cout<<Q.top().first<<" ";
	}
}

