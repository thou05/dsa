#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
int a[201][201],n,m;

int DFS(int u, int v){
	int dem=1;
	a[u][v]=1;
	stack<pair<int,int>> S; S.push({u,v});
	while(S.size()){
		int x = S.top().first, y = S.top().second;	//C++17 pair<int,int> {x,y} = S.top();
		S.pop();
		FOR(i,-1,1)
		FOR(j,-1,1) if(a[x+i][y+j]==0) {a[x+i][y+j]=1; S.push({x+i,y+j}); dem++;}
	}
	return dem;
}
int main(){
	cin>>n>>m;
	FOR(i,1,n)
	FOR(j,1,m) cin>>a[i][j];
	FOR(i,0,n+1) a[i][0]=a[i][m+1]=1;
	FOR(j,0,m+1) a[0][j]=a[n+1][j]=1;
	vector<int> res;
	FOR(i,1,n)
	FOR(j,1,m) if(a[i][j]==0) res.push_back(DFS(i,j));
	cout<<res.size()<<"\n";
	sort(res.begin(), res.end());
	for(auto x:res) cout<<x<<" ";
}

