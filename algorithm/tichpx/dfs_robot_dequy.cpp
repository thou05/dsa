#include<bits/stdc++.h>
using namespace std;

void DFS(int x, int y, set<pair<int,int>> &S){
	if(S.count({x,y})) return;
	S.insert({x,y});
	if(x%2==0) DFS(y, x/2, S);
	if(y%2!=0) DFS(y/2+1, x, S);
}

int main(){
	set<pair<int,int>> S;
	int x,y;
	cin>>x>>y;
	DFS(x,y,S);
	cout<<S.size();
}

