#include <bits/stdc++.h>
using namespace std;

const int MAX = 8;
int a[MAX][MAX];
int X[8] = {-2,-2,-1,-1, 1, 1, 2, 2};
int Y[8] = {-1, 1,-2, 2,-2, 2,-1, 1};
int n;
int dem = 0;

void output(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << setw(3) << a[i][j] << " ";
        }
        cout << endl;
    }
}

void diChuyen(int x, int y){
    ++dem;
    a[x][y] = dem;
    for(int i = 0; i < 8; i++){
        if(dem == n * n){
            cout << "Cac buoc di la: \n";
            output();
            exit(0);
        }
        int u = x + X[i];
        int v = y + Y[i];
        if(u >= 0 && u < n && v >= 0 && v < n && a[u][v] == 0){
            diChuyen(u, v);
        }
    }
    --dem;
    a[x][y] = 0;
}

int main(){
    cout << "Nhap n: ";
    cin >> n;
    if(n > MAX || n < 1){
        cout  << "Kich thuoc khong hop le!!";
        return 1;
    }
    int x0, y0;
    cout << "Nhap vi tri ban dau x, y: ";
    cin >> x0 >> y0;

    diChuyen(x0, y0);

    cout << "Khong tim duoc loi giai.\n";
    return 0;
}