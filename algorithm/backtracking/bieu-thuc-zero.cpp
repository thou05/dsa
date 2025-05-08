#include <bits/stdc++.h>

using namespace std;

void findExxpressions(int n, int current, string expr, int sum, int last) {
    if(current > n){
        if(sum == 0){
            cout << expr << " = 0" << endl;
        }
        return;
    }
}