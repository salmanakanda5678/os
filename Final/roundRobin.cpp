#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, tq;

    cout << "Enter number of processes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid input!" << endl;
        return 0;
    }

    int pid[n], at[n], bt[n], rt[n], ct[n], wt[n], tat[n];
    bool visited[n];

    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        cout << "Enter Arrival Time and Burst Time for P" << i + 1 << ": ";
        cin >> at[i] >> bt[i];

        if (at[i] < 0 || bt[i] <= 0)
        {
            cout << "Invalid input!" << endl;
            return 0;
        }

        rt[i] = bt[i];
        visited[i] = false;
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    if (tq <= 0)
    {
        cout << "Invalid Time Quantum!" << endl;
        return 0;
    }

    queue<int> q;

    int time = 0, completed = 0;
    double totalWT = 0, totalTAT = 0;

    cout << "\nGantt Chart:\n0";

    while (completed < n)
    {
        // Add processes to queue
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && !visited[i] && rt[i] > 0)
            {
                q.push(i);
                visited[i] = true;
            }
        }

        if (q.empty())
        {
            time++; // CPU idle
            continue;
        }

        int idx = q.front();
        q.pop();

        cout << " -> P" << pid[idx];

        int execTime = (rt[idx] < tq) ? rt[idx] : tq;
        rt[idx] -= execTime;
        time += execTime;

        cout << " -> " << time;

        // Add newly arrived processes again
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && !visited[i] && rt[i] > 0)
            {
                q.push(i);
                visited[i] = true;
            }
        }

        if (rt[idx] > 0)
        {
            q.push(idx);
        }
        else
        {
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            totalWT += wt[idx];
            totalTAT += tat[idx];

            completed++;
        }
    }

    cout << "\n -> End\n";

    cout << "\nProcess\tAT\tBT\tCT\tWT\tTAT\n";

    for (int i = 0; i < n; i++)
    {
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