#include <iostream>
using namespace std;

int main()
{
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resource types: ";
    cin >> m;

    if (n <= 0 || m <= 0)
    {
        cout << "Invalid input!" << endl;
        return 0;
    }

    int alloc[100][100], maxNeed[100][100], need[100][100];
    int avail[100], work[100];
    bool finish[100];
    int safeSeq[100];

    cout << "\nEnter Allocation Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];

    cout << "\nEnter Maximum Need Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maxNeed[i][j];

    cout << "\nEnter Available Resources:\n";
    for (int j = 0; j < m; j++)
        cin >> avail[j];

    // Need calculation
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = maxNeed[i][j] - alloc[i][j];

            if (need[i][j] < 0)
            {
                cout << "Invalid data!" << endl;
                return 0;
            }
        }
        finish[i] = false;
    }

    // Work = Available
    for (int j = 0; j < m; j++)
        work[j] = avail[j];

    int count = 0;

    while (count < n)
    {
        bool found = false;

        for (int i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                bool possible = true;

                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        possible = false;
                        break;
                    }
                }

                if (possible)
                {
                    for (int j = 0; j < m; j++)
                        work[j] += alloc[i][j];

                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found)
            break;
    }

    if (count == n)
    {
        cout << "\nSystem is in SAFE state.\nSafe Sequence: ";

        for (int i = 0; i < n; i++)
        {
            cout << "P" << safeSeq[i];
            if (i != n - 1)
                cout << " -> ";
        }

        cout << endl;
    }
    else
    {
        cout << "\nSystem is NOT in safe state (Deadlock may occur)." << endl;
    }

    return 0;
}

// 5 
// 3
// allocation
// 0 1 0 
// 2 0 0 
// 3 0 2 
// 2 1 1 
// 0 0 2
// max
// 7 5 3 
// 3 2 2
// 9 0 2
// 2 2 2
// 4 3 3 

// avail 
// 3 3 2 