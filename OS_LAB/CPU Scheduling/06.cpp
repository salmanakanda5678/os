// Question 6 — SJF Preemptive (SRTF)
// Write a program for Shortest Remaining Time First (SRTF) scheduling.
// Calculate:
// •	Completion Time 
// •	Waiting Time 
// •	Turnaround Time



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter Number Of Process: ";
    cin >> n;

    vector<int> at(n), bt(n), rt(n), ct(n), tat(n), wt(n);

    cout << "Enter AT and BT:\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << ": ";
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];   // remaining time
    }

    int time = 0, completed = 0;

    while(completed < n) {

        int idx = -1;
        int min_rt = INT_MAX;

        //  find process with shortest remaining time
        for(int i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(rt[i] < min_rt) {
                    min_rt = rt[i];
                    idx = i;
                }
            }
        }

        // CPU idle
        if(idx == -1) {
            time++;
            continue;
        }

        // execute for 1 unit time
        rt[idx]--;
        time++;

        // if finished
        if(rt[idx] == 0) {
            ct[idx] = time;
            completed++;
        }
    }

    // Calculate TAT and WT
    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i]  = tat[i] - bt[i];
    }

    // Output
    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "---------------------------------\n";

    float totalWT = 0, totalTAT = 0;

    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\n";

        totalWT += wt[i];
        totalTAT += tat[i];
    }

    cout << "\nAverage Waiting Time = " << totalWT / n;
    cout << "\nAverage Turnaround Time = " << totalTAT / n << endl;

    return 0;
}