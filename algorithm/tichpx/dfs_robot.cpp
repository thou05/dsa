#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,y;
	cin>>x>>y;
	set<pair<int,int>> Out; Out.insert({x,y});
	stack<pair<int,int>> S; S.push({x,y});
	while(S.size()){
		int u=S.top().first, v=S.top().second;
		S.pop();
		if(u%2==0){
			pair<int,int> z={v, u/2}; 
			if(Out.count(z)==0){ S.push(z); Out.insert(z);}
		}
		if(v%2!=0){
			pair<int,int> z={(v+1)/2, u}; 
			if(Out.count(z)==0){ S.push(z); Out.insert(z);}
		}
	}
	cout<<Out.size();
}

