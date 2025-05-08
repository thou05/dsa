#include <bits/stdc++.h>
using namespace std;

int n, buoc = 0;

void chuyen(int n, int A, int B, int C){
    if(n == 1){
        cout << "Buoc " << ++buoc << ": Chuyen dia tu " << A << " sang " << C << endl;
    }else{
        chuyen(n - 1, A, C, B);
        chuyen(1, A, B, C);
        chuyen(n - 1, B, A, C);
    }
}

int main(){
    cout << "Nhap so dia: ";
    cin >> n;
    cout << "Cac buoc chuyen dia la: \n";
    chuyen(n, 1, 2, 3);
}