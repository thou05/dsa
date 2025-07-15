#include<bits/stdc++.h>
using namespace std;

long np(int n){
	long a[n+5]={0,1,2}, b[n+5]={0,1,2}, c[n+5]={0,2,4};
	long long M = 1e9+7;
	for(int i=3; i<=n; i++){
		a[i] = c[i-1];
		b[i] = (b[i-1] + a[i-2])%M;
		c[i] = (a[i] + b[i])%M;
	}
	return c[n];
}

int main(){
	int n; cin>>n;
	cout<<np(n);
}

