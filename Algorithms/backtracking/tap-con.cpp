// liêt kê mọi cách chọn n phần tử trong tập m phần tử

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int a[MAX], n, m;    //chứa cấu hình hiện tại

void print(){
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void gen(int k){
    if(k > n){
        print();
        return;
    }
    for(int i = a[k-1] + 1; i <= m + n - k; i++){
        a[k] = i;
        gen(k + 1);
    }
}

//to hop chap k cua n
void backtrack(int i){
    for(int j = a[i-1] + 1; j <= m - n + i; j++){
        a[i] = j;
        if(i == n){
            print();
        } else {
            backtrack(i + 1);
        }
    }
}
int main(){
    n = 3; m = 5; a[0] = 0;
    gen(1);
    cout << "------------------" << endl;
    backtrack(1);
}