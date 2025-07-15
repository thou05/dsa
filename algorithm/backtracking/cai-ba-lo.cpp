#include <bits/stdc++.h>
using namespace std;

struct DoVat{
    string ten;
    int tl;
    int gt;
    int pa; // phuong an
};

void printResult(DoVat x[], int n){
    cout << "Phuong an: ";
    for(int i = 0; i < n; i++){
        if (x[i].pa == 1)
            cout << x[i].ten << " ";
    }
    cout << endl;
}

void attempt(DoVat x[], int i, int n, int w){
    for(int j = 0; j < n; j++){
        x[i].pa = j;
        if(i == n){
            int kl = 0;
            for(int k = 0; k < n; k++){
                kl += x[k].tl * x[k].pa;
            }
            if(kl <= w) printResult(x, n);
        }else{
            attempt(x, i + 1, n, w);
        }
    }
}

int main(){
    int n = 4, w = 37;
    DoVat sp[n];
    sp[0] = {"A", 15, 30, 0};
    sp[1] = {"B", 10, 20, 0};
    sp[2] = {"C", 12, 25, 0};
    sp[3] = {"D", 5, 10, 0};
    
    attempt(sp, 0, n, w);
    cout << "Tong so phuong an: " << (1 << n) << endl;

}