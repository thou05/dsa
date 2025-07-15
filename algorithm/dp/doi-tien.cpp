#include <bits/stdc++.h>
using namespace std;

int n = 5, M = 27;
int a[] = {0,1,2,3,5,10};
int L[6][28];

int doiTien(){
    for(int i = 1; i <= n; i++){
        for(int t = 1; t <= M; t++){
            if(t < a[i]) L[i][t] = L[i-1][t];
            else L[i][t] = min(L[i-1][t], L[i][t-a[i]] + 1);
        }
    }
    return L[n][M];
}

int main(){
    for(int i = 0; i <= n; i++){
        L[i][0] = 0;
        for(int j = 1; j <= M; j++){
            L[i][j] = INT_MAX;
        }
    }
    int kq = doiTien();
    cout << "So dong tien it nhat: " << kq << endl;

    cout << "L[i][j] = {" << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= M; j++){
            cout << L[i][j] << " ";
        }
        cout << endl;
    }
    cout << "}" << endl;
    // cout << "So to tien: " << endl;
    // for(int i = 1; i <= n; i++){
    //     cout << a[i] << " VND: " << L[i][M] << endl;
    //     M = M - a[i] * L[i][M];
    // }

    //----
    // cout << doiTien() << endl;
    // if(L[n][M] == INT_MAX) cout << "Khong doi duoc" << endl;
    // else cout << L[n][M] << endl;

}