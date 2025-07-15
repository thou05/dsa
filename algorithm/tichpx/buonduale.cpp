#include<bits/stdc++.h>
using namespace std;

int main(){
	queue<int> Q;
	int n,k,m,res=0,x;
	cin>>n>>k>>m;
	for(int i=1; i<n+k; i++){
		if(i<=n) cin>>x; else x=0;
		Q.push(x);
		while(Q.size()> static_cast<size_t>(k)) Q.pop();
		int t=0; 
		while(Q.size() && t+Q.front()<=m){
			t+=Q.front();
			Q.pop();
		}
		if(Q.size()){
			Q.front()-=m-t;
			t+=m-t;
		}
		res+=t;
	}
	cout<<res;
}

