#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ts first
#define dinh second
int main(){
	vector<pii> A[10004];
	priority_queue<pii, vector<pii>, greater<pii>> Q;
	map<int,int> L;
	int n,m,res=0;
	cin>>n>>m;
	for(int i=1; i<=m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		A[u].push_back({w,v});
		A[v].push_back({w,u});
	}
	Q.push({0,1});
	while(Q.size()){
		pii u = Q.top(); Q.pop();
		if(L[u.dinh] == -1) continue;
		res+=u.ts;
		L[u.dinh]=-1;
		for(auto v:A[u.dinh]){
			if(L[v.dinh] == 0 or L[v.dinh] > v.ts){
				L[v.dinh] = v.ts;
				Q.push(v);
			}
		}
	}
	cout<<res;
}

