#include <bits/stdc++.h>
using namespace std;

int nx, ny;
string X, Y;
int L[100][100];

int xauConChung(){
    for(int i = 1; i <= nx; i++){
        for(int j = 1; j <= ny; j++){
            if(X[i-1] == Y[j-1]){
                L[i][j] = L[i-1][j-1] + 1;
            }
            else{
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }
    return L[nx][ny];
}
int main(){
    X = "Conghoa";
    Y = "Congtru";
    nx = X.length();
    ny = Y.length();
    for(int i = 0; i <= nx; i++){
        L[i][0] = 0;
    }
    for(int j = 0; j <= ny; j++){
        L[0][j] = 0;
    }
    int kq = xauConChung();
    cout << "Do dai xau con chung dai nhat: " << kq << endl;
    cout <<"L[i,j] = {" << endl;
    for(int i = 0; i <= nx; i++){
        for(int j = 0; j <= ny; j++){
            cout << L[i][j] << " ";
        }
        cout << endl;
    }
    cout << "}" << endl;
}