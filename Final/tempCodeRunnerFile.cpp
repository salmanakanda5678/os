#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "enter number of processes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "invalid input!" << endl;
        return 0;
    }

    int pid[n], at[n], bt[n], ct[n], wt[n], tat[n];
    bool done[n];

    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        cout << "enter arrival time and burst time for p" << i + 1 << ": ";
        cin >> at[i] >> bt[i];

        if (at[i] < 0 || bt[i] <= 0)
        {
            cout << "invalid input!" << endl;
            return 0;
        }

        done[i] = false;
    }

    int time = 0, completed = 0;
    double totalwt = 0, totaltat = 0;

    cout << "\ngantt chart:\n0";

    while (completed < n)
    {
        int idx = -1;
        int minbt = 1e9;

        for (int i = 0; i < n; i++)
        {
            if (!done[i] && at[i] <= time)
            {
                if (bt[i] < minbt)
                {
                    minbt = bt[i];
                    idx = i;
                }
                else if (bt[i] == minbt)
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

        cout << " -> p" << pid[idx];

        time += bt[idx];

        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];

        done[idx] = true;
        completed++;

        totalwt += wt[idx];
        totaltat += tat[idx];
    }

    cout << " -> end\n";

    cout << "\nprocess\tat\tbt\tct\twt\ttat\n";

    for (int i = 0; i < n; i++)
    {
        cout << "p" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    cout << "\naverage waiting time = " << totalwt / n << endl;
    cout << "average turnaround time = " << totaltat / n << endl;

    return 0;
}