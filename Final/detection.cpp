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

    int allocation[100][100], request[100][100];
    int available[100], work[100];
    bool finish[100];
    int safeSeq[100];

    cout << "\nEnter Allocation Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> allocation[i][j];

    cout << "\nEnter Request Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> request[i][j];

    cout << "\nEnter Available Resources:\n";
    for (int j = 0; j < m; j++)
        cin >> available[j];

    // Initialize work and finish
    for (int j = 0; j < m; j++)
        work[j] = available[j];

    for (int i = 0; i < n; i++)
        finish[i] = false;

    int count = 0;

    // Detection algorithm
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
                    if (request[i][j] > work[j])
                    {
                        possible = false;
                        break;
                    }
                }

                if (possible)
                {
                    for (int j = 0; j < m; j++)
                        work[j] += allocation[i][j];

                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found)
            break;
    }

    // Result
    bool deadlock = false;

    cout << "\nResult:\n";

    for (int i = 0; i < n; i++)
    {
        if (!finish[i])
        {
            cout << "P" << i << " is in deadlock state\n";
            deadlock = true;
        }
    }

    if (!deadlock)
    {
        cout << "No Deadlock in the system\n";

        cout << "Safe execution order: ";
        for (int i = 0; i < count; i++)
        {
            cout << "P" << safeSeq[i];
            if (i != count - 1)
                cout << " -> ";
        }
        cout << endl;
    }

    return 0;
}


// 5 
// 3

// alloc
// 0 1 0
// 2 0 0 
// 3 0 3
// 2 1 1
// 0 0 2

// rqst
// 0 0 0 
// 2 0 2
// 0 0 0 
// 1 0 0 
// 0 0 2 

// avail 
// 0 0 0 