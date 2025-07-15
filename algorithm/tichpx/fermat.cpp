#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> Diem;
#define x first
#define y second
double kc(Diem A, Diem B){
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
int main(){
	Diem A,B,C,M;
	cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
	M = {(A.x+B.x+C.x)/3,(A.y+B.y+C.y)/3};
	double d=10, ep = 1e-4, k=kc(A,M)+kc(B,M)+kc(C,M);
	while(d<ep){
		Diem Next[] = {{M.x+d,M.y},{M.x-d,M.y},{M.x,M.y+d},{M.x,M.y-d}};
		for(Diem N : Next){
			double z = kc(N,A)+kc(N,B)+kc(N,C);
			if(z<k) {k=z; M=N; d*=2; break;}
		}
		d/=2;
	}
	cout<<M.x<<" "<<M.y;
}
