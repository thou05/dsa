//cài đặt thuật toán tìm kiếm nhị phân trên mảng theo 2 pp
//- đệ quy
//- lặp

#include <bits/stdc++.h>
using namespace std;

int binarySearchRecursive(int a[], int left, int right, int target){
    if(left > right){
        return -1;
    }
    int mid = left + (right - left) / 2;
    if(a[mid] == target){
        return mid;
    }else if(a[mid] > target){
        return binarySearchRecursive(a, left, mid - 1, target);
    }else{
        return binarySearchRecursive(a, mid + 1, right, target);
    }
}

int binarySearchIterative(int a[], int size, int target){
    int left = 0, right = size - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if(a[mid] == target){
            return mid;
        }else if(a[mid] > target){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 3, 5, 7, 9, 11, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    cout << "binary search (recusive): " << binarySearchRecursive(arr, 0, size - 1, target) << endl;

    cout << "binary search (iterative): " << binarySearchIterative(arr, size, target) << endl;
}