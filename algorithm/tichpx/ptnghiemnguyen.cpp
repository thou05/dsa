#include<bits/stdc++.h>
using namespace std;

int x[100],n,M,dem=0;

void TRY(int k, int t){
	if(k==n){
		for(int i=1; i<k; i++) cout<<x[i]<<"+";
		cout<<M-t<<" = "<<M<<"\n";
		dem++;
	}
	else for(x[k]=0;x[k]<=M-t;x[k]++) TRY(k+1, t+x[k]);
}

int main(){
	cin>>n>>M;
	TRY(1,0);
	cout<<"\nSo nghiem "<<dem;
}

