#include<bits/stdc++.h>
using namespace std;

int main(){
	unsigned long a,b,c,n;
	cin>>a>>b>>c>>n;
	if(a>b && b>c){
		if((n-(a-b)-(a-c)) % 3 ==0 && (2*a-b-c) <= n ) cout<<"YES";
		else cout<<"NO";
	}else if(b>c && c>a){
		if((n-(b-a)-(b-c)) % 3 ==0 && (2*b-a-c) <= n ) cout<<"YES";
		else cout<<"NO";
	}else{
		if((n-(c-b)-(c-a)) % 3 ==0 && (2*c-a-b) <= n ) cout<<"YES";
		else cout<<"NO";
	}
	
}

