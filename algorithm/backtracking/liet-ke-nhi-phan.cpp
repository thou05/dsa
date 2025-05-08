#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int a[MAX], n;    //chứa cấu hình hiện tại

void print(){
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
//CACH 1
//sinh dan a[1], a[2], ..., a[k]
void gen(int k){
    //sinh xong day
    if(k > n) print();

    //chua sinh xong
    else{
        a[k] = 0; gen(k + 1);
        a[k] = 1; gen(k + 1);
    }
    
}

//CACH 2
void backtrack(int i){
    for(int j = 0; j <= 1; j++){
        a[i] = j;
        if(i == n){  //nếu tìm đến i cuối thì print
            print(); 
        }
        else{
            backtrack(i + 1);  //chưa tìm đến i cuối thì tăng i lên
        }
    }
}

int main(){
    n = 3;
    gen(1);
    cout << "------------------" << endl;
    backtrack(1);
    return 0;
}