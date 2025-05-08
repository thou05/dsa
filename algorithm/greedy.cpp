/*
cho n nhiệm vụ, mỗi nhiệm vụ cần làm trong 1 đơn vị thời gian. 
Nhiệm vụ thứ i có thời gian hoàn thành di, nếu hoàn thành sau 
thời hạn di sẽ bị phạt mất pi. Bắt đầu từ thời điểm 0 và tại mỗi 
thời điểm chỉ thực hiện 1 nhiệm vụ. Hãy lên lịch thực hiện các 
nhiệm vụ sao cho số tiền phạt và ít nhất bằng phương pháp tham lam
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Task {
    int deadline, penalty;
    bool operator<(const Task &other) const {
        return deadline < other.deadline; // Sắp xếp tăng dần theo deadline
    }
};

int minPenaltySchedule(vector<Task> &tasks) {
    sort(tasks.begin(), tasks.end()); // Sắp xếp theo deadline
    priority_queue<int> pq;
    int currentTime = 0, totalPenalty = 0;
    
    for (const auto &task : tasks) {
        if (currentTime < task.deadline) {
            pq.push(task.penalty);
            currentTime++;
        } else if (!pq.empty() && pq.top() > task.penalty) {
            pq.pop();
            pq.push(task.penalty);
        } else {
            totalPenalty += task.penalty; // Không thể làm nhiệm vụ này đúng hạn
        }
    }
    return totalPenalty;
}

int main() {
    int n;
    cin >> n;
    vector<Task> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].deadline >> tasks[i].penalty;
    }
    cout << "Minimum penalty: " << minPenaltySchedule(tasks) << endl;
    return 0;
}
