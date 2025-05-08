#include <bits/stdc++.h>

using namespace std;

const int n = 4;

int cost[n][n] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

pair<int, vector<int>> tspGreedy(int start) {
    vector<bool> visited(n, false);
    vector<int> path;
    int totalCost = 0;
    int currCity = start;

    visited[currCity] = true;
    path.push_back(currCity);

    for (int i = 0; i < n -1; i++) {
        int nextCity = -1;
        int minCost = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && cost[currCity][j] < minCost) {
                minCost = cost[currCity][j];
                nextCity = j;
            }
        }

        visited[nextCity] = true;
        totalCost += minCost;
        currCity = nextCity;
        path.push_back(currCity);
    }

    totalCost += cost[currCity][start];
    path.push_back(start);

    return {totalCost, path};
}

int main() {
    int startCity = 0;
    cout << "Bat dau tu thanh pho: " << startCity << endl;

    auto result = tspGreedy(startCity);

    cout << "Tong chi phi nho nhat la: " << result.first << endl;
    cout << "Lich trinh: ";
    for (int city : result.second) {
        cout << city << " ";
    }
}
