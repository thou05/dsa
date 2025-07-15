#include<bits/stdc++.h>
using namespace std;

long catalan(long n){
	long c[n+5]={};
	c[0]=1;
	for(int i=1; i<=n; i++){
		c[i]=0;
		for(int j=0; j<i; j++){
			c[i] += c[j]*c[i-j-1];
		}
	}
	return c[n];
}

int main(){
	long n;
	cin>>n;
	cout<<catalan(n);
}

