#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
int n, a[MAX], dem = 0;

bool antoan(int k, int i){
    for(int j = 1; j < k; j++){
        if(a[j] == i || a[j] + j == k + i || a[j] - j == i - k){
            return false; //không an toàn
        }
    }
    return true; //an toàn
}

void print(){
    dem++;
    cout << dem << endl;
}

void dat(int k){
    if(k > n){
        print();
        return;
    }
    for(int i = 1; i <= n; i++){
        if(antoan(k, i)){
            a[k] = i; //gán giá trị cho a[k]
            dat(k + 1); //tiếp tục gán
        }
    }

}

//CACH 2
void ghinhan(){
    dem++;
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
bool legal;
void XepHau(int k){
    for(int i = 1; i <= n; i++){
        legal = true;
        for(int j = 1; j < k; j++){
            if(a[j] == i || (abs(i - a[j]) == k - j)){
                legal = false;
            }
        }
        if(legal){
            a[k] = i;
            if(k == n) ghinhan();
            else XepHau(k + 1);
        }
    }
}

bool b[MAX], c[MAX], d[MAX];
int dem3 = 0;
//CACH 3: toi uu thoi gian chay
void print2(){
    dem3++;
}
void dat2(int k){
    if(k > n){
        print2(); 
        return;
    }
    for(int i = 1; i <= n; i++){
        if(b[i] && c[n+k-i] && d[k+i]){
            b[i] = c[n+k-i] = d[k+i] = false; //đánh dấu
            a[k] = i; //gán giá trị cho a[k]
            dat2(k + 1); //tiếp tục gán
            b[i] = c[n+k-i] = d[k+i] = true; //bỏ đánh dấu
        }
    }
}


int main(){
    n = 5; //số lượng quân hậu
    dat(1); //bắt đầu gán từ k = 1
    cout << "------------------" << endl;
    XepHau(1); //bắt đầu xếp từ k = 1
    cout << "------------------" << endl;
    for(int i = 0; i < MAX; i++){
        b[i] = c[i] = d[i] = true; //khởi tạo mảng đánh dấu
    }
    dat2(1); //bắt đầu gán từ k = 1
    cout << dem3 << endl; //in ra số cách xếp
}