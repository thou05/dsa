#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight, value;
    double ratio;
};

// giảm dần
bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}

double greedyKnapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<Item> items(n);
    
    for (int i = 0; i < n; i++) {
        items[i] = {weights[i], values[i], (double)values[i] / weights[i]};
    }
    
    sort(items.begin(), items.end(), cmp);
    
    double maxValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (W >= items[i].weight) {
            W -= items[i].weight;
            maxValue += items[i].value;
        } else {
            maxValue += items[i].ratio * W;
            break;
        }
    }
    
    return maxValue;
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
    
    double maxValue = greedyKnapsack(W, weights, values, n);
    cout << "Giá trị lớn nhất có thể lấy là: " << maxValue << endl;
    
    return 0;
}
