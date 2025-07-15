#include<bits/stdc++.h>
using namespace std;

map<int,int> P;
void path(int s, int f){
	list<int> L(1,f);
	while(f!=s){
		f=P[f];
		L.push_front(f);
	}
	for(auto x:L) cout<<(x==s?"":"->")<<x;
}
void PATH(int s, int f){
	if(s==f) cout<<s;
	else{
		PATH(s,P[f]); 
		cout<<"->"<<f;
	}
}
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
				P[u+x]=u;
			}
		}
	}
	if(M.count(f)==0) cout<<-1;
	else{ cout<<M[f]<<"\n"; PATH(s,f);}
}

