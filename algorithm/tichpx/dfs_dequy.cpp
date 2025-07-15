#include<bits/stdc++.h>
using namespace std;

void DFS(int n, set<int> &O){
	if(O.count(n)) return;
	O.insert(n);
	for(int a=1; a*a<=n; a++){
		if(n%a==0) DFS((a-1)*(n/a+1), O);
	}
}

int main(){
	int n;
	cin>>n;
	set<int> S;
	DFS(n, S);
	for(auto x:S) cout<<x<<" ";
}

