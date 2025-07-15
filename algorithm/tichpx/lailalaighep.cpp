#include<bits/stdc++.h>
using namespace std;
set<char> V={'A','E','I','O','U'};
string x,y;
int n;
void TRY(string z, int k, int d){
	if(d>=3) return;
	if(k==n){
		cout<<z<<"\n";
	}
	else{
		TRY(z+x[k], k+1, V.count(x[k])?0:d+1);
		if(y[k]!=x[k]) 	TRY(z+y[k], k+1, V.count(y[k])?0:d+1);
	}
}
int main(){
	cin>>x>>y;
	n=x.length();
	TRY("", 0,0);
}

