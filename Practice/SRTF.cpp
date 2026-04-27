// C++ program to implement SRTF Scheduling
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of Processes: ";
    cin >> n;

    vector<int> at(n), bt(n), rt(n);
    int completionTime, smallest;
    int remain = 0, time = 0, sum_wait = 0, sum_turnaround = 0;

    for(int i = 0; i < n; i++) {
        cout << "Enter arrival time for Process P" << i+1 << ": ";
        cin >> at[i];
        cout << "Enter burst time for Process P" << i+1 << ": ";
        cin >> bt[i];
        rt[i] = bt[i];
    }

    cout << "\nProcess\tTurnaround Time\tWaiting Time\n";

    while(remain != n) {
        smallest = -1;
        for(int i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(smallest == -1 || rt[i] < rt[smallest]) {
                    smallest = i;
                }
            }
        }

        if(smallest != -1) {
            rt[smallest]--;
            if(rt[smallest] == 0) {
                remain++;
                completionTime = time + 1;
                int turnaround = completionTime - at[smallest];
                int waiting = turnaround - bt[smallest];
                cout << "P[" << smallest+1 << "]\t\t" << turnaround << "\t\t" << waiting << endl;
                sum_wait += waiting;
                sum_turnaround += turnaround;
            }
        }
        time++;
    }

    cout << "\nAverage Waiting Time = " << (float)sum_wait / n << endl;
    cout << "Average Turnaround Time = " << (float)sum_turnaround / n << endl;

    return 0;
}
