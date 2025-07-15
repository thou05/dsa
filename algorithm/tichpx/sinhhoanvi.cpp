#include<bits/stdc++.h>
using namespace std;

int d[1000]={}, x[1000], n;

void TRY(int k, int n){
	if(k-1==n) {
		bool check = true;
		for(int i=1; i<=n; i++){
			if((x[i-1]+x[i])%4 == 0){
				break;
				check = false;
			}
		}
		if(check){
			for(int i=1; i<=n; i++){
				 cout<<x[i]<<(i==n?"\n":"");
			}
		}
	}
	else{
		for(int t=1; t<=n; t++){
			if(d[t]==0){
				d[t]=1;
				x[k]=t;
				TRY(k+1,n);
				d[t]=0;
			}
		}
	}
}

int main(){
	cin>>n;
	TRY(1,n);
}

