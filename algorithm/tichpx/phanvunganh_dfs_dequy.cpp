#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
int a[201][201],n,m,res[2000]={},k=0;

void DFS(int u, int v, int &dem){
	if(a[u][v]) return;
	dem++;
	a[u][v]=1;
	FOR(i,-1,1)
	FOR(j,-1,1) DFS(u+i,v+j,dem);
}

int main(){
	cin>>n>>m;
	FOR(i,1,n)
	FOR(j,1,m) cin>>a[i][j];
	FOR(i,0,n+1) a[i][0]=a[i][m+1]=1;
	FOR(j,0,m+1) a[0][j]=a[n+1][j]=1;
	FOR(i,1,n)
	FOR(j,1,m) if(a[i][j]==0) {DFS(i,j,res[k]); k++;}
	cout<<k<<"\n";
	sort(res, res+k);
	FOR(i,0,k-1) cout<<res[i]<<" ";
}

