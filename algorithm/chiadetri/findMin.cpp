//cài đặt thuật toán tìm phần tử nhỏ nhất trong 1 mảng 
//các số thực theo chiến lược chia để trị

#include <bits/stdc++.h>
using namespace std;

double findMin(double a[], int left, int right){
    if(left == right){
        return a[left];
    }
    int mid = left + (right - left) / 2;
    double minLeft = findMin(a, left, mid);
    double minRight = findMin(a, mid + 1, right);
    return min(minLeft, minRight);
}

int main(){
    double arr[] = {3.5, 1.2, 5.7, -2.8, 4.9, 0.6};
    int n = sizeof(arr) / sizeof(arr[0]);

    double minElement = findMin(arr, 0, n - 1);
    cout << "min index: " << minElement << endl;
}