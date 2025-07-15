#include<bits/stdc++.h>
using namespace std;

struct ss{
	bool operator()(int a, int b){return a%3==b%3?a<b:a%3<b%3;}	//chan trc le sau
};

int main(){
//	priority_queue<int> Q;		multiset<int> Q;
//	priority_queue<int, vector<int>, greater<int> Q;	
	int n;
	cin>>n;
	multiset<int, ss> Q;
	for(int i=0, x; i<n; i++){
		cin>>x;
		Q.insert(x);
	} 
	while(Q.size()){
		cout<<*Q.begin()<<" ";
		Q.erase(Q.begin());
	}
}

