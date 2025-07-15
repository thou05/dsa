#include<bits/stdc++.h>
using namespace std;

struct node{
	char kt;
	int ts;
	node *left, *right;
	node(char c, int t, node*L=0, node*R=0){
		kt=c;
		ts=t;
		left=L;
		right=R;
	}
};

struct ss{
	bool operator()(node*p, node*q){return p->ts > q->ts;}
};

void TRY(string z, node*p){
	if(!p->left) cout<<p->kt<<" : "<<z<<"\n";
	else{
		TRY(z+"0",p->left);
		TRY(z+"1",p->right);
	}
}

int main(){
	string s;
	map<char,int> F;
	long x, res=0;
	priority_queue<node*, vector<node*>, ss> Q;
	cin>>s;
	for(auto c:s) F[c]++;
	for(auto f:F) Q.push(new node(f.first, f.second));
	while(Q.size()-1){
		node *x= Q.top(); Q.pop();
		node *y= Q.top(); Q.pop();
		res += x->ts + y->ts;
		Q.push(new node('_',x->ts+y->ts, x, y));
	}
	cout<<res<<"\nMa hoa nhu sau";
	TRY("",Q.top());
}

