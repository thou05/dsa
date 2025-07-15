#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	long res=0;
	cin>>n>>k;
	int a[n];
	for(auto &x:a) cin>>x;
	sort(a,a+n,greater<int>());
	for(int i=0; i<n && a[i]>i*k; i++) res+=a[i]-i*k;
	cout<<res;
}

