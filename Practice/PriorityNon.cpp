// C++ program to implement Priority Scheduling with Arrival Time
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> bt(n), at(n), pr(n), wt(n), tat(n), temp(n+1);
    float awt = 0, atat = 0;

    cout << "Enter burst time, arrival time & priority for each process:\n";
    for(int i = 0; i < n; i++) {
        cin >> bt[i] >> at[i] >> pr[i];
    }

    // Sorting by arrival time (simple bubble sort)
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(at[i] > at[j]) {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(pr[i], pr[j]);
            }
        }
    }

    temp[0] = 0;
    cout << "\nProcess\tBurst\tArrival\tPriority\tWaiting\tTurnaround\n";

    for(int i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;
        temp[i+1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];

        cout << "P[" << i+1 << "]\t" << bt[i] << "\t" << at[i] << "\t"
             << pr[i] << "\t\t" << wt[i] << "\t" << tat[i] << endl;
    }

    awt /= n;
    atat /= n;

    cout << "\nAverage Waiting Time = " << awt << endl;
    cout << "Average Turnaround Time = " << atat << endl;

    return 0;
}
