// C++ program to implement Round Robin Scheduling
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, qt, count = 0, temp, sq = 0;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> bt(n), wt(n), tat(n), rem_bt(n);
    float awt = 0, atat = 0;

    cout << "Enter burst time of each process:\n";
    for(int i = 0; i < n; i++) {
        cin >> bt[i];
        rem_bt[i] = bt[i];
    }

    cout << "Enter quantum time: ";
    cin >> qt;

    while(true) {
        count = 0;
        for(int i = 0; i < n; i++) {
            temp = qt;
            if(rem_bt[i] == 0) {
                count++;
                continue;
            }
            if(rem_bt[i] > qt) {
                rem_bt[i] -= qt;
            } else {
                temp = rem_bt[i];
                rem_bt[i] = 0;
            }
            sq += temp;
            tat[i] = sq;
        }
        if(count == n) break;
    }

    cout << "\nProcess\tBurst Time\tTurnaround Time\tWaiting Time\n";
    for(int i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        awt += wt[i];
        atat += tat[i];
        cout << i+1 << "\t" << bt[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;
    }

    awt /= n;
    atat /= n;

    cout << "\nAverage Waiting Time = " << awt;
    cout << "\nAverage Turnaround Time = " << atat << endl;

    return 0;
}
