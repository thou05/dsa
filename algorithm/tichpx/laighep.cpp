#include<bits/stdc++.h>
using namespace std;
string x,y;
int n;
void TRY(string z, int k){
	if(k==n){
		cout<<z<<"\n";
	}
	else{
		TRY(z+x[k], k+1);
		if(y[k]!=x[k]) TRY(z+y[k], k+1);
	}
}
int main(){
	cin>>x>>y;
	n=x.length();
	TRY("", 0);
}

