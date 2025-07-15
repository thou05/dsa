#include <bits/stdc++.h>
using namespace std;

int n = 4, W = 6;
int g[] = {0,2,1,4,3};
int v[] = {0,3,3,4,2};
int L[5][7];

int xepDoVat(){
    //int t = 0;
    for(int i = 1; i <= n; i++){
        for(int t = 1; t <= W; t++){
            if(t < g[i]) L[i][t] = L[i-1][t];
            else L[i][t] = max(L[i-1][t], L[i][t-g[i]] + v[i]);
        }
    }
    return L[n][W];
}

int main(){
    for(int i = 1; i <= n;i++){
        for(int t = 1; t <= W; t++){
            L[i][t] = 0;
        }
    }
    //memset(L, 0, sizeof(L));    
    int kq = xepDoVat();
    cout << "Cac do vat: " << endl;
    for(int i = 1; i <= n; i++){
        for(int t = 1; t <= W; t++){
            cout << L[i][t] << " ";
        }
        cout << endl;
    }
    cout << "Tong gia tri lon nhat: " << kq << endl;
}