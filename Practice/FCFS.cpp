// FCFS Scheduling without struct
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[20], wt[20], tat[20];
    int totwtime = 0, totttime = 0;

    // Input burst times
    for (int i = 0; i < n; i++) {
        cout << "Burst time of process " << i + 1 << ": ";
        cin >> bt[i];
    }

    // First process
    wt[0] = 0;
    tat[0] = bt[0];
    totwtime += wt[0];
    totttime += tat[0];

    // Remaining processes
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        totwtime += wt[i];
        totttime += tat[i];
    }

    // Output results
    cout << "\nProcess\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }

    cout << "\nTotal waiting time: " << totwtime;
    cout << "\nAverage waiting time: " << (float)totwtime / n;
    cout << "\nTotal turnaround time: " << totttime;
    cout << "\nAverage turnaround time: " << (float)totttime / n;

    return 0;
}
