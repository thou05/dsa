#include<bits/stdc++.h>
using namespace std;

int x[1000]={1}, n, dem;
void TRY(int k, int t){
	if(t==n){
//		for(int i=1; i<=k-1; i++){
//			cout<<x[i]<<"+";
//		}
//		cout<<x[k]<<" = "<<n<<"\n";
		dem++;
	}
	else{ 
		for(x[k+1]=x[k]; x[k+1] + t <= n; x[k+1]++){
			TRY(k+1, t+x[k+1]);
		}	
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		dem=0;
		TRY(0,0);
		cout<<dem<<"\n";
	}
}

