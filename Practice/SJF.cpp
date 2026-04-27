// C++ program to implement SJF Scheduling (without struct)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "SJF Algorithm (C++ without struct)\n";
    cout << "Enter the total number of processes: ";
    cin >> n;

    vector<int> bt(n), wt(n), tat(n), pid(n);
    int sum = 0, w_total = 0, t_total = 0;

    // Input burst times
    for(int i = 0; i < n; i++) {
        cout << "Enter burst time of process " << i+1 << ": ";
        cin >> bt[i];
        pid[i] = i+1;
    }

    // Sort by burst time (Bubble Sort)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(bt[j] > bt[j+1]) {
                swap(bt[j], bt[j+1]);
                swap(pid[j], pid[j+1]);
            }
        }
    }

    // Calculate waiting & turnaround times
    for(int i = 0; i < n; i++) {
        wt[i] = sum;
        sum += bt[i];
        tat[i] = sum;
    }

    // Print results
    cout << "\nPID\tBurst\tWait\tTurnaround\n";
    for(int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
        w_total += wt[i];
        t_total += tat[i];
    }

    float w_avg = (float)w_total / n;
    float t_avg = (float)t_total / n;

    cout << "\nTotal Waiting Time : " << w_total;
    cout << "\nAverage Waiting Time : " << w_avg;
    cout << "\nTotal Turnaround Time : " << t_total;
    cout << "\nAverage Turnaround Time : " << t_avg << endl;

    return 0;
}
