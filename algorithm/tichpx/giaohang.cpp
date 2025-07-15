#include<bits/stdc++.h>
using namespace std;

int main(){
	list<int> A[100005];
	priority_queue<int> Q;
	long n, res=0, a, b;
	cin>>n;
	while(n--){
		cin>>a>>b;
		A[a].push_back(b);
	}
	for(int i=1e5; i>0; i--){
		for(auto x : A[i]) Q.push(x);
		if(Q.size()){
			res += Q.top();
			Q.pop();
		}
	}
	cout<<res;
}

