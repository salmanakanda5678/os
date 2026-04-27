#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5, r = 3;

    int alloc[5][3] = {{0, 0, 1},
                       {3, 0, 0},
                       {1, 0, 0},
                       {2, 3, 2},
                       {0, 0, 3}};

    int maxm[5][3] = {{7, 6, 3},
                      {3, 2, 2},
                      {8, 0, 2},
                      {2, 1, 2},
                      {5, 2, 3}};

    int avail[3] = {2, 3, 2};

    int need[5][3];

    // Calculate Need
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            need[i][j] = maxm[i][j] - alloc[i][j];

    vector<int> safeSeq;
    vector<bool> finished(n, false);

    int count = 0;

    while (count < n)
    {
        bool found = false;

        for (int i = 0; i < n; i++)
        {
            if (!finished[i])
            {
                bool possible = true;

                for (int j = 0; j < r; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        possible = false;
                        break;
                    }
                }

                if (possible)
                {
                    for (int j = 0; j < r; j++)
                        avail[j] += alloc[i][j];

                    safeSeq.push_back(i);
                    finished[i] = true;
                    found = true;
                    count++;
                }
            }
        }

        if (!found)
        {
            cout << "System is NOT in safe state (Deadlock possible)\n";
            return 0;
        }
    }

    cout << "Safe Sequence: ";
    for (int i = 0; i < n; i++)
        cout << "P" << safeSeq[i] + 1 << " ";

    cout << endl;

    return 0;
}