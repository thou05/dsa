#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	map<char,int> F;
	long x, res=0;
	priority_queue<long, vector<long>, greater<long>> Q;
	cin>>s;
	for(auto c:s) F[c]++;
	for(auto f:F) Q.push(f.second);
	while(Q.size()-1){
		x = Q.top(); Q.pop();
		x += Q.top(); Q.pop();
		res += x;
		Q.push(x);
	}
	cout<<res;
}

