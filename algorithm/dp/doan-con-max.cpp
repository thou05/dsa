#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int n, a[MAX], s[MAX];

void input(){

}

int main(){
    input();
    s[1] = a[1];
    for(int i = 2; i <= n; i++){
        if(s[i-1] <= 0) s[i] = a[i];
        else s[i] = s[i-1] + a[i];
    }
    cout << "Max sum: ";
    
}