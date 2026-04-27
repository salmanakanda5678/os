#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input!";
        return 0;
    }

// lower number higher priority

    int pid[n], at[n], bt[n], pr[n], rt[n], ct[n], wt[n], tat[n];
    bool done[n];

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;

        cout << "Enter AT BT Priority for P" << i + 1 << ": ";
        cin >> at[i] >> bt[i] >> pr[i];

        if (at[i] < 0 || bt[i] <= 0 || pr[i] < 0) {
            cout << "Invalid input!";
            return 0;
        }

        rt[i] = bt[i];
        done[i] = false;
    }

    int time = 0, completed = 0;

    while (completed < n) {

        int idx = -1;
        int best = 1e9;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {

                if (pr[i] < best) {
                    best = pr[i];
                    idx = i;
                }
                else if (pr[i] == best) {
                    if (idx == -1 || at[i] < at[idx])
                        idx = i;
                }
            }
        }

        if (idx == -1) {
            time++; // CPU idle
            continue;
        }

        rt[idx]--;
        time++;

        if (rt[idx] == 0) {
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            done[idx] = true;
            completed++;
        }
    }

    double avgWT = 0, avgTAT = 0;

    cout << "\nProcess\tAT\tBT\tPR\tCT\tWT\tTAT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << pr[i] << "\t"
             << ct[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    cout << "\nAverage Waiting Time = " << avgWT / n << endl;
    cout << "Average Turnaround Time = " << avgTAT / n << endl;

    return 0;
}