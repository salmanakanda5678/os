#include <iostream>
using namespace std;

int findLRU(int time[], int n)
{
    int min = time[0], pos = 0;

    for (int i = 1; i < n; i++)
    {
        if (time[i] < min)
        {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main()
{
    int n, frames;

    cout << "Enter number of pages: ";
    cin >> n;

    int pages[100];

    cout << "Enter page reference string: ";
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> frames;

    int frame[100], time[100];

    // initialize
    for (int i = 0; i < frames; i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }

    int pagefaults = 0, counter = 0;

    for (int i = 0; i < n; i++)
    {
        bool found = false;

        // check hit
        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
            {
                counter++;
                time[j] = counter;
                found = true;
                break;
            }
        }

        if (!found)
        {
            int pos = findLRU(time, frames);

            frame[pos] = pages[i];
            counter++;
            time[pos] = counter;
            pagefaults++;
        }

        // frame status print
        cout << "Page " << pages[i] << " -> ";
        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == -1)
                cout << "- ";
            else
                cout << frame[j] << " ";
        }
        cout << endl;
    }

    cout << "\nTotal Page Faults = " << pagefaults << endl;

    return 0;
}

// 12 
// 2 3 2 1 5 2 4 5 3 2 5 2 
// 3 