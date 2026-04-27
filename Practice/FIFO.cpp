// C++ program to simulate FIFO Page Replacement Algorithm
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, f, pf = 0, count = 0;

    cout << "Enter the length of reference string -- ";
    cin >> n;

    vector<int> rs(n);
    cout << "Enter the reference string -- ";
    for(int i = 0; i < n; i++)
        cin >> rs[i];

    cout << "Enter number of frames -- ";
    cin >> f;

    vector<int> m(f, -1);

    cout << "\nThe Page Replacement Process is -- \n";

    for(int i = 0; i < n; i++) {
        int k;
        for(k = 0; k < f; k++) {
            if(m[k] == rs[i])
                break;
        }

        if(k == f) {
            m[count++] = rs[i];
            pf++;
        }

        for(int j = 0; j < f; j++)
            cout << "\t" << m[j];

        if(k == f)
            cout << "\tPF No. " << pf;

        cout << "\n";

        if(count == f)
            count = 0;
    }

    cout << "\nThe number of Page Faults using FIFO are " << pf << endl;

    return 0;
}
