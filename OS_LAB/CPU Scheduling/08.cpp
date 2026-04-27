// Question 8 — Priority Scheduling
// Write a program to implement:
// •	Non-preemptive priority scheduling
// or 
// •	Preemptive priority scheduling
// Calculate:
// •	Completion Time 
// •	Waiting Time 
// •	Turnaround Time



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> at(n), bt(n), pr(n), ct(n), tat(n), wt(n);
    vector<bool> done(n, false);

    cout << "Enter AT, BT, Priority (lower = higher priority):\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << ": ";
        cin >> at[i] >> bt[i] >> pr[i];
    }

    int time = 0, completed = 0;

    while(completed < n) {

        int idx = -1;
        int best_pr = INT_MAX;

        //  find highest priority process
        for(int i = 0; i < n; i++) {
            if(at[i] <= time && !done[i]) {
                if(pr[i] < best_pr) {
                    best_pr = pr[i];
                    idx = i;
                }
            }
        }

        // CPU idle
        if(idx == -1) {
            time++;
            continue;
        }

        // execute fully (NON-PREEMPTIVE)
        ct[idx] = time + bt[idx];
        time = ct[idx];

        done[idx] = true;
        completed++;
    }

    // TAT & WT
    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // output
    cout << "\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    cout << "--------------------------------------\n";

    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << pr[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\n";
    }

    return 0;
}