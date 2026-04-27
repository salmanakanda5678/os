// Question 5 — SJF Non-Preemptive
// Implement Shortest Job First (Non-Preemptive) scheduling algorithm.
// Display:
// •	Gantt Chart 
// •	Waiting Time 
// •	Turnaround Time
// Input : 
// 4
// 1 3 
// 2 4
// 1 2 
// 4 4


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cout<<"Enter Number Of Process : \n";
    cin>>n ; 
    vector<int>at(n),bt(n),ct(n),tt(n),wt(n),index(n);
    vector<bool>done(n,false);
    cout<<"Enter AT and BT \n";
    for(int i = 0 ; i<n ; i++){
        cout<<"P"<<i+1 << ":";
        cin>>at[i]>>bt[i];
    }

    int current_time = 0 ,completed = 0 ;


    while(completed < n ){
        int idx = -1 , min = 9999;

        for(int i = 0 ; i <n ; i++){
            if( at[i] <= current_time && done[i] == false){
                if(bt[i] < min){
                    min = bt[i];
                    idx = i;
                }
            }
        }

        if(idx == -1){
            current_time++;
            continue;
        }

        ct[idx] = bt[idx]+current_time;
        current_time = ct[idx];
        done[idx] = true;
        index[completed] = idx+1 ;
        completed++; 
    }

    for(int i = 0 ; i < n ;i++){
        tt[i] = ct[i] - at[i];
        wt[i] = tt[i]-bt[i];
    }

cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tt[i] << "\t"
             << wt[i] << "\n";
    }
     cout << "\nGantt Chart:\n| ";
    for(int i = 0; i < n; i++) {
        cout << "P" << index[i] << " | ";
    }

    cout << endl;

}