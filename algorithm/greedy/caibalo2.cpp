#include<bits/stdc++.h>
using namespace std;
struct vat{
	int tl;
	int gt;
	float tile(){
		return (float)gt/tl;
	}
};
bool ss(vat a, vat b){
	return a.tile()>b.tile();
}
void caibalo(int w, vector<vat>& dovat){
	sort(dovat.begin(), dovat.end(), ss);
	int tongtl=0, tonggt=0;
	for(auto dv : dovat){
		int sl= w/dv.tl;
		if(sl>0){
			tongtl=tongtl+sl*dv.tl;
			tonggt=tonggt+sl*dv.gt;
			w=w-sl*dv.tl;
		}
	}
	cout<<"Tong trong luong la "<<tongtl<<endl;
	cout<<"Tong gia tri la "<<tonggt;
}
int main(){
	vector<vat>dovat={{10,25},{15,30},{4,6},{2,2}};
	int w=37;
	caibalo(w,dovat);
}


