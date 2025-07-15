#include<bits/stdc++.h>
using namespace std;

int n, a[100], T=0, res=1e9;

void TRY(int k, int A, int B){
	if(res<=1) return;
	if(k==n) res = min(res,B-A);
	else{
		if(A+a[k+1]<=T/2) TRY(k+1, A+a[k+1], B);
		if(B+a[k+1]<=(T+res)/2) TRY(k+1, A, B+a[k+1]);
	}
}

int main(){
	cin>>n;
	for(int i=1; i<=n; i++) {cin>>a[i]; T+=a[i];}
	TRY(0,0,0);
	cout<<res;
}

