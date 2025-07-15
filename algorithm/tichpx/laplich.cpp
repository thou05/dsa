#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> sk;
#define bd first
#define kt second
bool ss(sk u, sk v){return u.kt<v.kt;}
int main(){
	int n, res = 0, t = -1e9;
	cin>>n;
	sk A[n];
	for(auto &a:A){
		cin>>a.bd>>a.kt;
	}
	sort(A,A+n,ss);
	for(auto a:A) if(a.bd>t){res++; t=a.kt;}
	cout<<res;
}

