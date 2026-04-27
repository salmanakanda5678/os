// Question 4 — FCFS Scheduling
// Write a program to implement First Come First Serve (FCFS) CPU scheduling algorithm and calculate:
// •	Waiting Time 
// •	Turnaround Time 
// •	Average Waiting Time 
// •	Average Turnaround Time


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cout<<"Enter Number Of Process : "<<endl;
    cin>>n ;

    int b[n];
    cout<<"Enter Process Brust Time : "<<endl;
    for(int i = 0 ; i<n ;i++){
        cin >>b[i];
    }

     cout<<" \nProcess Brust Time Are : "<<endl;

    for(int i = 0 ; i<n ;i++){
        cout<<b[i] << " ";
    }
    // Calculation Of Waiting Time 
    int w[n];
    w[0] = 0;
    for(int i = 1 ; i<n;i++ ){
        w[i] = w[i-1] + b[i-1];
    }
     cout<<"\nProcess Waiting Time Are : "<<endl;
    for(int i = 0 ; i<n ;i++){
        cout<<w[i] << " ";
    }

    int TotalWT = 0 ;
    double AWT = 0.0;
// Total WT
    for(int j = 0 ; j < n ; j++){
        TotalWT+=w[j];
    }
    cout<<"\nTotal Waiting Time is : "<<TotalWT <<endl;
    AWT = double(TotalWT )/ n ;
    cout<<"Average Waiting Time is : "<<AWT <<endl;

    // Tournaround Time 


    int ta[n];
    for (int i = 0 ; i< n ; i++){
        ta[i] = w[i] + b[i];
    }
    
    cout<<"Process Turnaround Time Are : "<<endl;
    for(int i = 0 ; i<n ;i++){
        cout<<ta[i] << " ";
    }
    // Total TA
    int TotalTA = 0 ;
    for(int j = 0 ; j < n ; j++){
        TotalTA+=ta[j];
    }

    double avgTA ;
    avgTA = double(TotalTA)/n;
    cout<<"\nAverage Turn Around Time is : "<<avgTA <<endl;
    
}