#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> sk;
#define bd first
#define kt second
bool ss(sk u, sk v){return u.kt<v.kt;}	
void sol(){
	int n, res = 0, t1 = -1e9, t2 = -1e9;
	cin>>n;
	sk A[n];
	for(auto &a:A) cin>>a.bd>>a.kt;
	sort(A,A+n,ss);
	for(auto a:A) {
		if(t1<t2) swap(t1,t2);
		if(a.bd>t1){res++; t1=a.kt;}
		else if(a.bd>t2){res++; t2=a.kt;}
	}
	cout<<res<<"\n";
}
int main(){
	int tt;
	cin>>tt;
	while(tt--) sol();
}

