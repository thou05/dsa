#include<bits/stdc++.h>
using namespace std;
void TRY(int *x, int k, int n){
	if(k-1==n){
		for(int i=1; i<=n; i++){
			cout<<x[i];
		}
		cout<<"\n";
	}
	else{
		for(x[k]=0; x[k]<=1; x[k]++) TRY(x,k+1,n);
	}
}
int main(){
	int n, x[1000];
	cin>>n;
	TRY(x,1,n);
}

