// Question 7 — Round Robin Scheduling
// Implement Round Robin Scheduling using a user-defined time quantum.
// Display:
// •	Gantt Chart 
// •	Waiting Time 
// •	Turnaround Time

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter time quantum: ";
    cin >> tq;

    vector<int> at(n), bt(n), rt(n), ct(n), tat(n), wt(n);
    vector<bool> done(n, false);

    cout << "Enter AT and BT:\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << ": ";
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];   // remaining time
    }

    int time = 0, completed = 0;

    while(completed < n) {

        bool all_done = true;

        for(int i = 0; i < n; i++) {
            if(at[i] <= time && !done[i]) {
                all_done = false;
                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    done[i] = true;
                    completed++;
                }
            }
        }

        // If all processes are done, break
        if(all_done) {
            break;
        }
    }

    // Calculate TAT and WT
    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i]  = tat[i] - bt[i];
    }

    // Output
    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << endl;
    }

    return 0;
}