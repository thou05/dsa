#include<bits/stdc++.h>
using namespace std;

int n, a[1000], M, res=1e9;

void TRY(int k, int t, int T){
	if(k==n){
		if((M-T)%a[n]==0) res = min(res, t+ (M-T)/a[n]);
		return;
	}
	for(int x=0; x+t<res && T+a[k]*x<=M; x++) TRY(k+1, t+x, T+a[k]*x);
}

int main(){
	cin>>n>>M;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	TRY(1,0,0);
	if(res==1e9) cout<<"\nKhong doi duoc"; else cout<<res;

}

