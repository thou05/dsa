#include<bits/stdc++.h>
using namespace std;
int c[100][1000] = {}, n,M,a[100];

void TRACE(int n, int M){
	if(c[n][M]==0) return;
	while(c[n][M]==c[n-1][M]) n--;
	TRACE(n,M-a[n]);
	cout<<a[n]<<" ";
}

int main(){
	cin>>n>>M;
	for(int i=1; i<=n; i++) cin>>a[i];
	fill(c[0]+1, c[0]+M+1, 1e9); //for(int j=1; j<=M; j++) c[0][j] = 1e9;
	for(int i=1; i<=n; i++)
	for(int j=1; j<=M; j++)
	if(a[i]>j) c[i][j] = c[i-1][j];
	else c[i][j] = min(c[i-1][j], 1+c[i][j-a[i]]);
	if(c[n][M]==1e9) cout<<"Khong doi duoc";
	else cout<<c[n][M]<<"\n"; TRACE(n,M);
}

