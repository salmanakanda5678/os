#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid input!" << endl;
        return 0;
    }

    int pid[n], at[n], bt[n], pr[n];
    int ct[n], wt[n], tat[n];
    bool done[n];

    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        cout << "Enter Arrival Time, Burst Time, Priority for P" << i + 1 << ": ";
        cin >> at[i] >> bt[i] >> pr[i];

        if (at[i] < 0 || bt[i] <= 0 || pr[i] < 0)
        {
            cout << "Invalid input!" << endl;
            return 0;
        }

        done[i] = false;
    }

    int time = 0, completed = 0;
    double totalwt = 0, totaltat = 0;

    while (completed < n)
    {
        int idx = -1;
        int best = 1e9;

        for (int i = 0; i < n; i++)
        {
            if (!done[i] && at[i] <= time)
            {
                if (pr[i] < best)
                {
                    best = pr[i];
                    idx = i;
                }
                else if (pr[i] == best)
                {
                    if (idx == -1 || at[i] < at[idx])
                        idx = i;
                }
            }
        }

        if (idx == -1)
        {
            time++; // CPU idle
            continue;
        }

        time += bt[idx];   // non-preemptive execution
        ct[idx] = time;

        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];

        totalwt += wt[idx];
        totaltat += tat[idx];

        done[idx] = true;
        completed++;
    }

    cout << "\nProcess\tAT\tBT\tPR\tCT\tWT\tTAT\n";

    for (int i = 0; i < n; i++)
    {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << pr[i] << "\t"
             << ct[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << totalwt / n << endl;
    cout << "Average Turnaround Time = " << totaltat / n << endl;

    return 0;
}