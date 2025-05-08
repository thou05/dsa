#include <iostream>
#include <vector>

using namespace std;

void findPartitions(int n, int start, vector<int>& current)
{
    if (n == 0)
    {
        for (size_t i = 0; i < current.size(); i++)
        {
            if (i > 0) cout << " + ";
            cout << current[i];
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= n; i++)
    {
        current.push_back(i);
        findPartitions(n - i, i, current);
        current.pop_back();
    }
}

void generatePartitions(int n)
{
    vector<int> current;
    findPartitions(n, 1, current);
}

int main()
{
    int N;
    cout << "Nhập N (1 <= N <= 30): ";
    cin >> N;
    
    if (N < 1 || N > 30)
    {
        cout << "N không hợp lệ!" << endl;
        return 1;
    }

    generatePartitions(N);
    return 0;
}