#include <iostream>
using namespace std;

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

    int frame[100];
    int size = 0;

    int pagefaults = 0, pagehits = 0;
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        bool found = false;

        // Check if page already in frame
        for (int j = 0; j < size; j++)
        {
            if (frame[j] == pages[i])
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            pagehits++;
        }
        else
        {
            pagefaults++;

            if (size < frames)
            {
                frame[size++] = pages[i];
            }
            else
            {
                frame[index] = pages[i];
                index = (index + 1) % frames;
            }
        }
    }

    cout << "\nPage Faults = " << pagefaults << endl;
    cout << "Page Hits = " << pagehits << endl;

    return 0;
}

// 12 
// 2 3 2 1 5 2 4 5 3 2 5 2 
//3