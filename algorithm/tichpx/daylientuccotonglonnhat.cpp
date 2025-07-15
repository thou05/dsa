#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	long a[n+5]={-1},c[n+5]={},res = LONG_MIN;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		c[i] = max(c[i-1], (long)0) + a[i];
		res=max(res,c[i]);
	}
	cout<<res;
}

