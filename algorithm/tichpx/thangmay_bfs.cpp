#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k,m,s,f;
	cin>>n>>k>>m>>s>>f;
	queue<int> Q; Q.push(s);
	map<int,int> M={{s,0}};	//M[s]=0
	while(Q.size() and M.find(f)==M.end()){		//M.count(f) == 0 
		int u = Q.front();
		Q.pop();
		for(auto x:{k,-m}){
			if(0<u+x && u+x<=n && M.count(u+x)==0){
				Q.push(u+x);
				M[u+x]=M[u]+1;
			}
		}
	}
	if(M.count(f)==0) cout<<-1;
	else cout<<M[f];
}

