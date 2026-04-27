#include <iostream>
using namespace std;

int main()
{
    int n, r;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> r;

    int alloc[100][100], maxm[100][100], need[100][100];
    int avail[100];

    // Allocation input
    cout << "Enter Allocation Matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < r; j++)
        {
            cin >> alloc[i][j];
        }
    }

    // Maximum input
    cout << "Enter Maximum Matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < r; j++)
        {
            cin >> maxm[i][j];
        }
    }

    // Available input
    cout << "Enter Available Resources:\n";
    for(int i = 0; i < r; i++)
    {
        cin >> avail[i];
    }

    // Need calculation
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < r; j++)
        {
            need[i][j] = maxm[i][j] - alloc[i][j];
        }
    }

    int finish[100] = {0};
    int safeSeq[100];
    int count = 0;

    while(count < n)
    {
        int found = 0;

        for(int i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(int j = 0; j < r; j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if(possible)
                {
                    for(int j = 0; j < r; j++)
                    {
                        avail[j] += alloc[i][j];
                    }

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        // If no process found → unsafe
        if(found == 0)
        {
            cout << "\nSystem is NOT in safe state (Deadlock possible)\n";
            return 0;
        }
    }

    // Safe state output
    cout << "\nSystem is in SAFE state\n";
    cout << "Safe Sequence: ";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << safeSeq[i] + 1 << " ";
    }

    cout << endl;

    return 0;
}