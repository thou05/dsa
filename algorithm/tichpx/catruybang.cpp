#include<bits/stdc++.h>
using namespace std;

int main(){
	long n,a,b,c;
	cin>>n>>a>>b>>c;
	long dp[n+5]={};
	for(int i = 1; i<=n; i++) {
		dp[i]=-1;
		for(auto z : {a,b,c})	if(i>=z && dp[i-z]>=0) dp[i] = max(dp[i-z]+ 1,dp[i]);
//		if(i>=a && dp[i-a]>=0) dp[i] = max(dp[i-a]+ 1,dp[i]);
//		if(i>=b && dp[i-b]>=0) dp[i] = max(dp[i-b]+ 1,dp[i]);
//		if(i>=c && dp[i-c]>=0) dp[i] = max(dp[i-c]+ 1,dp[i]);
	}
	cout<<dp[n]; 
}

