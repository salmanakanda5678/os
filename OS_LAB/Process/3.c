// Question 3-Process
// Create two child processes from one parent process and display the process tree.


// #include <bits/stdc++.h>
#include<bits/stdc++.h>
#include <unistd.h>   
#include <sys/types.h>

using namespace std;

int main() {

    pid_t pid1, pid2;

    // First child
    pid1 = fork();

    if(pid1 == 0) {
        // Child 1
        cout << "Child 1 -> PID: " << getpid()
             << " Parent PID: " << getppid() << endl;
    }
    else {
        // Parent creates second child
        pid2 = fork();

        if(pid2 == 0) {
            // Child 2
            cout << "Child 2 -> PID: " << getpid()
                 << " Parent PID: " << getppid() << endl;
        }
        else {
            // Parent process
            cout << "Parent -> PID: " << getpid() << endl;
        }
    }

    return 0;
}