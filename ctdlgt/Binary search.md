Created: 202411111425
Tags: 

28tech... chua xem het
```cpp
#include <bits/stdc++.h>
using namespace std;

//cac phan tu phai duoc sap xep
//l, r, mid = (l+r) / 2
//r = mid - 1
//l = mid + 1
//cai dat bang de quy

bool binarySearch(int a[], int n, int x){
    int l = 0, r = n - 1;
    while(l < r){
        int m = (l + r) / 2;
        if(a[m] == x){
            return true;
        }else if(a[m] < x){ //mid nho hon x -> tim ben phai, l = m + 1
            l = m + 1;
        }else{ //tim ben trai -> r = m - 1
            r = m - 1;
        }

    }
    return false;
}

//de quy
bool binarySearch2(int a[], int l, int r, int x){
    if(l > r){
        return false;
    }
    int m = (l + r) / 2;
    if(a[m] == x){
        return true;
    }else if(a[m] < x){
        return binarySearch2(a, m + 1, r, x);
    }else{
        return binarySearch2(a, l, m - 1, x);
    }
}
//hieu hieu, tuyet

int main(){
    int n, x; cin >> n >> x;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(binarySearch2(a, 0, n - 1, x)){
        cout << "FOund";
    }else{
        cout << "Nope";
    }
    if(binarySearch(a, n , x)){
        cout << "found";
    }else{
        cout << "No no";
    }

    //thu vien co san
    //dung iterator
    //binary_search(a + x, a + y, key) => a[x] -> a[y-1]
    //vd (a + 1, a + 4, key) => tim a1, a2, s3

    //neu dung vector
    //binary_search(v.begin(), v.end(), key) => tim ca mang
    //binary_search(v.begin() + x, v.begin() + y, key) => tim doan x -> y - 1
    if(binary_search(a, a + n, x)){
        cout << "yet";
    }else{
        cout << "nau";
    }

    int m, y; cin >> m >> y;
    vector<int> v(m);
    for(int i = 0; i < m; i++){
        cin >> v[i];
    }
    if(binary_search(v.begin(), v.begin() + 4, y)){
        cout << "co";
    }else{
        cout << "nau nau";
    }

}

```


-----
## References
1. https://youtu.be/dB2DWSKGLj8?list=PLux-_phi0Rz0Hq9fDP4TlOulBl8APKp79
