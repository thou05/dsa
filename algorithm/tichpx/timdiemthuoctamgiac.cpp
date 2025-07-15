#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> Diem;
#define x first 
#define y second
double const ep = 1e-4;

double bpkc(Diem A, Diem B){
	return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}

Diem tim(Diem A, Diem B, Diem C, Diem M){
	Diem res=A;
	double mind = 1e18;
	while(abs(A.x-B.x)>ep or abs(A.y-B.y)>ep){
		Diem C = {(A.x+B.x)/2,(A.y+B.y)/2};
		bpkc(M,A) > bpkc(M,B) ? A = C : B = C;
	}
	return A;
}

int main(){
	int q; cin>>q;
	while(q--){
		Diem A,B,C,M;
		cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y>>M.x>>M.y;
		Diem N = tim(A,B,M);
		cout<<setprecision(3)<<fixed<<N.x<<" "<<N.y<<endl;
	}
}

