#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Process {
    int id, at, bt, pr;
    int rt, ct, tat, wt;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    // Input
    for(int i = 0; i < n; i++) {
        cout << "Enter AT, BT, Priority for P" << i+1 << ": ";
        cin >> p[i].at >> p[i].bt >> p[i].pr;
        p[i].id = i + 1;
        p[i].rt = p[i].bt;
    }

    int completed = 0, time = 0;
    float totalWT = 0, totalTAT = 0;

    while(completed != n) {
        int highest = -1;

        for(int i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].rt > 0) {
                if(highest == -1 ||
                   p[i].pr < p[highest].pr ||
                   (p[i].pr == p[highest].pr && p[i].at < p[highest].at)) {
                    highest = i;
                }
            }
        }                               //Lower number higher priority

        if(highest != -1) {
            p[highest].rt--;

            if(p[highest].rt == 0) {
                completed++;
                p[highest].ct = time + 1;
                p[highest].tat = p[highest].ct - p[highest].at;
                p[highest].wt = p[highest].tat - p[highest].bt;

                totalWT += p[highest].wt;
                totalTAT += p[highest].tat;
            }
        }

        time++;
    }

    // Output Table
    cout << "\n--------------------------------------------------------\n";
    cout << "PID\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    cout << "--------------------------------------------------------\n";

    for(int i = 0; i < n; i++) {
        cout << "P" << p[i].id << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].pr << "\t"
             << p[i].ct << "\t"
             << p[i].tat << "\t"
             << p[i].wt << endl;
    }

    cout << "--------------------------------------------------------\n";

    cout << fixed << setprecision(2);
    cout << "Average Turnaround Time = " << totalTAT / n << endl;
    cout << "Average Waiting Time = " << totalWT / n << endl;

    return 0;
}