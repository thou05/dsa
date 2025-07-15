/*
Giả sử có 1 máy ATM có các loại tiền 100.000 vnđ, 50.000 vnđ, 40.000 vnđ và 10.000 vnđ 
và mỗi loại tiền đều có số lượng không hạn chế. Khách hàng cần rút một số tiền n vnđ 
(tính chẵn đến 10.000 vnđ, hay n chia hết cho 10.000). 
Hãy tìm phương án trả tiền sao cho trả đủ n vnđ và số tờ tiền phải trả là ít nhất
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 4;
int c[MAX] = {100000, 50000, 40000, 10000};
int n, a[MAX];

int main(){
    cout <<"N = ";
    cin >> n;
    for(int i = 0; i < MAX; i++){
        a[i] = n / c[i];
        cout << "So to " << c[i] << " VND: " << a[i] << endl;
        n = n - c[i] * a[i];
    }
}