// Question 4 — FCFS Scheduling
// Write a program to implement First Come First Serve (FCFS) CPU scheduling algorithm and calculate:
// •	Waiting Time 
// •	Turnaround Time 
// •	Average Waiting Time 
// •	Average Turnaround Ti


#include <bits/stdc++.h>
using namespace std ;

int main(){
    int n,totalTT = 0,totalWT = 0;
    double avgTT,avgWT;

    cout <<"Enter Number Of Process : "<<endl;
    cin >>n;

    vector<int>at(n),bt(n),wt(n),tt(n),ct(n);

    cout <<"Enter Process AT and BT : "<<endl;
    
    for (int i =0 ; i <n ;i++){
        cin>>at[i]>>bt[i];
    }

    // Calculation Of Completion Time 
    int current_time = 0 ;

    for(int i = 0 ; i < n ; i++){
        if ( current_time < at[i]){
            current_time = at[i];

        }

        ct[i] = bt[i] + current_time;
        current_time = ct[i];
    }

    // Calculation of TAT 
    for(int i = 0 ; i < n ; i++){
        tt[i] = ct[i] - at[i];
    }

    // Calculation of WT 
    for(int i = 0 ; i < n ; i++){
        wt[i] = tt[i] - bt[i];
    }

    for(int i = 0 ; i<n ; i++){
        totalTT += tt[i];
        totalWT += wt[i];
    }
    avgTT = double(totalTT)/n;
    avgWT = double(totalWT) /n;

    cout<<" AT  |"<<" BT  |"<<" CT  |"<<" TAT  |" << " WT  |"<<endl;

    for(int i = 0 ; i < n ; i++){
        cout <<" "<<at[i]<<"  |"<<" "<<bt[i]<<"    |"<<" "<<ct[i]<<"   |"<<" "<<tt[i]<<"    |"<<" "<<wt[i]<<"   |"<<endl;
    }

    cout<<"\n Total TAT : "<<totalTT<<endl;
    cout<<"\n Total WT : "<<totalWT<<endl;
    cout<<"\n Average TAT : "<<avgTT<<endl;
    cout<<"\n Average WT : "<<avgWT<<endl;

}