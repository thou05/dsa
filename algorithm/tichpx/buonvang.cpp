#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	int res=0, a[n], z=-INT_MAX;
	for(auto &x:a) cin>>x;
	for(int i=n-1; i>=0;i--){
		if(z<a[i]) z=a[i];
		else res +=z-a[i];
	}
	cout<<res;
}

