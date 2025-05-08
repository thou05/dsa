#include <bits/stdc++.h>
using namespace std;

struct dv {
    int khoiluong, giatri;
};

int quyhoachdong(int n, vector<dv>& cacdo) {
    vector<int> dp(n + 1, 0);
    
    for (int w = 0; w <= n; w++) {
        for (auto &dv : cacdo) {
            if (dv.khoiluong <= w) {
                dp[w] = max(dp[w], dp[w - dv.khoiluong] + dv.giatri);
            }
        }
    }
    return dp[n];
}

int main() {
    vector<dv> cacdo = {{10,25}, {15,30}, {4,6}, {2,2}};
    int n;
    cin >> n;
    cout << "Gia tri toi da" << quyhoachdong(n, cacdo) << endl;
}

