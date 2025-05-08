/*
Công ty dự kiến tổ chức N cuộc họp, cuộc họp thứ k bắt đầu từ thời 
điểm s[k] và kết thúc vào thời điểm f[k].
Phòng họp công ty không thể tổ chức 2 cuộc họp cùng một lúc, vì vậy
phải loại bỏ một số cuộc họp nếu chúng có thời gian họp chồng lần
lên nhau.
Tìm cách tổ chức nhiều cuộc họp nhất có thể.
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 8;
int s[MAX] = {0, 1, 3, 3, 4, 5, 6, 8};   //start 
int f[MAX] = {6, 4, 5, 7, 8, 9, 10, 11};  //finish
int a[MAX];   //mang chua thu tu sap xep tang dan theo thoi diem ket thuc

bool cmp(int i, int j) {
    return f[i] < f[j];
}

int main(){
    for(int i = 0; i < MAX; i++){
        a[i] = i;
    }
    sort(a, a + MAX, cmp);
    cout << "Cuoc hop duoc chon: " << a[0];
    int e = f[a[0]];  //end
    for(int i = 1; i < MAX; i++){
        if(s[a[i]] >= e){
            cout << " " << a[i];
            e = f[a[i]];
        }
    }
}