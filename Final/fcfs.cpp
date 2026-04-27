#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    int pid[n], at[n], bt[n], ct[n], wt[n], tat[n];

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;

        cout << "Enter Arrival Time and Burst Time for P" << i + 1 << ": ";
        cin >> at[i] >> bt[i];

        if (at[i] < 0 || bt[i] <= 0) {
            cout << "Invalid input!" << endl;
            return 0;
        }
    }

    // Sort by Arrival Time (simple bubble sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                swap(at[j], at[j + 1]);
                swap(bt[j], bt[j + 1]);
                swap(pid[j], pid[j + 1]);
            }
        }
    }

    int time = 0;
    float totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++) {

        if (time < at[i])
            time = at[i];  // CPU idle

        ct[i] = time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        time = ct[i];

        totalWT += wt[i];
        totalTAT += tat[i];
    }

    cout << "\nProcess\tAT\tBT\tCT\tWT\tTAT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << totalWT / n << endl;
    cout << "Average Turnaround Time = " << totalTAT / n << endl;

    return 0;
}

// 3 1 
// 4 5
// 0 2 
// 3 7 
// 5 5 
