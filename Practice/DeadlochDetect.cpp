#include <iostream>
using namespace std;

int main()
{
    int n, r;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> r;

    int alloc[100][100], req[100][100];
    int avail[100];

    // Allocation Matrix input
    cout << "Enter Allocation Matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < r; j++)
        {
            cin >> alloc[i][j];
        }
    }

    // Request Matrix input
    cout << "Enter Request Matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < r; j++)
        {
            cin >> req[i][j];
        }
    }

    // Available resources
    cout << "Enter Available Resources:\n";
    for(int i = 0; i < r; i++)
    {
        cin >> avail[i];
    }

    int finish[100] = {0};

    // Mark processes with zero allocation as finished
    for(int i = 0; i < n; i++)
    {
        int zero = 1;
        for(int j = 0; j < r; j++)
        {
            if(alloc[i][j] != 0)
            {
                zero = 0;
                break;
            }
        }
        if(zero)
            finish[i] = 1;
    }

    int changed;

    do {
        changed = 0;

        for(int i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(int j = 0; j < r; j++)
                {
                    if(req[i][j] > avail[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if(possible)
                {
                    // Release resources
                    for(int j = 0; j < r; j++)
                    {
                        avail[j] += alloc[i][j];
                    }

                    finish[i] = 1;
                    changed = 1;
                }
            }
        }

    } while(changed);

    // Check deadlock
    int deadlock = 0;

    cout << "\nDeadlocked Processes: ";
    for(int i = 0; i < n; i++)
    {
        if(finish[i] == 0)
        {
            cout << "P" << i+1 << " ";
            deadlock = 1;
        }
    }

    if(!deadlock)
        cout << "None (No Deadlock)";

    cout << endl;

    return 0;
}