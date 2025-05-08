#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int a[MAX], n;
bool b[MAX];  //mảng đánh dấu
int c[MAX];  //mảng lưu hoán vị

void print(int n){
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

//CACH 1
void gen(int k){
    //nếu sinh đc n phần tử thì in ra 
    if(k > n){
        print(n);
        return;
    }
    //chon giá trị cho a[k]
    for(int i = 1; i <= n; i++){
        if(b[i]){         //nếu chưa đánh dấu
            b[i] = false; //đánh dấu
            a[k] = i; //gán giá trị cho a[k]
            gen(k + 1); //tiếp tục sinh
            b[i] = true; //bỏ đánh dấu
        }
    }
}

//CACH 2
void hoanvi(int i){
    for(int j = 1; j <= n; j++){
        if(c[j] == 0){  //chưa được chọn
            a[i] = j + 1;  
            c[j] = 1; //đánh dấu
            if(i == n){ //nếu đã chọn đủ n phần tử
                print(n);
            } else {
                hoanvi(i + 1); //tiếp tục chọn
            }
            c[j] = 0; //bỏ đánh dấu
        }
    }
}

int main(){
    n = 3;
    for(int i = 1; i <= n; i++){
        b[i] = true; //khởi tạo mảng đánh dấu
    }
    gen(1); //bắt đầu sinh từ k = 1
    cout << "------------------" << endl;
    hoanvi(1); //bắt đầu hoán vị từ i = 1
}