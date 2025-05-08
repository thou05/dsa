#include <iostream>
#include <vector>
using namespace std;

int unboundedKnapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<int> dp(W + 1, 0);
    
    for (int w = 0; w <= W; w++) {
        for (int i = 0; i < n; i++) {
            if (weights[i] <= w) {
                dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
            }
        }
    }
    
    return dp[W];
}

int main() {
    int n, W;
    cout << "Nhập số lượng loại vật phẩm: ";
    cin >> n;
    cout << "Nhập trọng lượng tối đa của ba lô: ";
    cin >> W;
    
    vector<int> weights(n), values(n);
    cout << "Nhập trọng lượng và giá trị của từng loại vật phẩm:\n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }
    
    int maxValue = unboundedKnapsack(W, weights, values, n);
    cout << "Giá trị lớn nhất có thể lấy là: " << maxValue << endl;
    
    return 0;
}