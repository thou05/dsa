#include <iostream>
using namespace std;

#define MAX 100
#define INF 1000000

int n = 4; 
int cost[MAX][MAX] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

bool visited[MAX];  
int path[MAX];    
int totalCost = 0; 

int findNearest(int current) {
    int minCost = INF;
    int nearest = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[current][i] < minCost) {
            minCost = cost[current][i];
            nearest = i;
        }
    }

    return nearest;
}

void greedyTSP() {
    int current = 0; 
    visited[current] = true;
    path[0] = current;

    for (int i = 1; i < n; i++) {
        int next = findNearest(current);
        visited[next] = true;
        totalCost += cost[current][next];
        path[i] = next;
        current = next;
    }

    totalCost += cost[current][0];
    path[n] = 0;
}

int main() {
    for (int i = 0; i < n; i++)
        visited[i] = false;

    greedyTSP();

    cout << "Duong di: ";
    for (int i = 0; i <= n; i++)
        cout << path[i] << " ";
    cout << "\nTong chi phi: " << totalCost << endl;

    return 0;
}