/*
Một cửa hàng bán lẻ sử dụng các đồng xu 1, 5, 10, 25, 100 cents để trả lại tiền thừa cho khách. 
Đưa ra cách thức trả cho khách sử dụng ít đồng tiền nhất.
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 5;
int c[MAX] = {100, 25, 10, 5, 1};
int n, a[MAX];

int main(){
    cout <<"N = ";
    cin >> n;
    for(int i = 0; i < MAX; i++){
        a[i] = n / c[i];
        cout << "So xu " << c[i] << " la: " << a[i] << endl;
        n = n - c[i] * a[i];
    }
}