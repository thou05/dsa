#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
map<pii,pii> P;
void path(pii z){
	if(z==pii(0,0)) cout<<"(0,0)";
	else{
		path(P[z]);
		cout<<"->("<<z.first<<","<<z.second<<")";
	}
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	queue<pii> Q;	Q.push({0,0});
	map<pii,int> M={{{0,0},0}};		//M[{0,0}]=0;
	while(Q.size()){
		int x = Q.front().first, y = Q.front().second, t=x+y;
		Q.pop();
		pii Next[]={{0,y},{n,y},{x,0},{x,m},{max(0,t-m), min(t,m)},{min(t,n), max(0, t-n)}};
		for(auto z:Next){
			if(M.count(z)==0){
				Q.push(z);
				M[z]=M[{x,y}]+1;
				P[z]={x,y};
				if(z.first==k or z.second==k){
					cout<<M[z]<<"\n";
					path(z);
					return 0;
				}
			}
		}
	}
	cout<<"\nKhong dong duoc nuoc";
}

