#include <bits/stdc++.h>

using namespace std;

vector<string> Dau = {"+", "-", ""};
vector<string> S = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
vector<string> D(10);  //luu dau giua cac so
vector<string> M(100);  //luu bieu thuc 
int N, dem;

void test(){
    string st = "", so = "";
    int i, k = 0, l;
    long T = 0;
    int dau = 0;
    for(i = 0; i < N; i++){
        st = st + D[i] + S[i];
    }
    l = st.length();
    while (k < l){
        if(st[k] >= '1' && st[k] <= '9'){
            so = so + st[k];
        }else{
            T = T + stoi(so, nullptr, 10);
        }
    }
    if(T == 0){
        dem++;
        M[dem] = st;
    }
    
}

void zeroExpr(int i){
    for(int j = 0; j < 3; j++){
        D[i] = Dau[j];
        if(i == N - 1) test();
        else zeroExpr(i + 1);
    }
}

int main(){
    cout << "Nhap N: ";
    cin >> N;
    dem = 0;
    zeroExpr(1);
    cout << "So bieu thuc = " << dem << endl;
}