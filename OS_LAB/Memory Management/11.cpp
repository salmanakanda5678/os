// Question 11 — FIFO Page Replacement
// Write a program to implement the First-In First-Out (FIFO) page replacement algorithm.
// The program should:
// •	accept page reference string 
// •	accept number of frames 
// •	count page faults and page hits

// Input :
// 12
// 2 3 2 1 5 2 4 5 3 2 5 2
// 3

// For Checking Belady's Anomaly
// Input Without Belady's Anomaly : 
// 12 
// 1 2 3 4 1 2 5 1 2 3 4 5
// 3

// Input With Belady's Anomaly : 
// 12 
// 1 2 3 4 1 2 5 1 2 3 4 5
// 4




#include<bits/stdc++.h>
using namespace std ;

int main(){
    int n;
    cout <<"Enter Number Of Page : "<<endl;
    cin>>n;

    vector<int>page(n);
    cout <<"Enter Enter reference pages : "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>page[i];
    }

    int f;
    cout <<"Enter Number Of Frame : "<<endl;
    cin>>f;

    vector<int>frame(f,-1);
    int pointer = 0 ,HT= 0 ,MS=0;

    for( int i = 0 ; i < n ; i++){
        bool found = false ;

        for(int j = 0 ; j<f ; j++){
            if(frame[j] == page[i]){
                found = true;
                break;
            }
        }

        if(found){
            HT++;
        }
        else{
            frame[pointer] = page[i];
            pointer = (pointer + 1) % f;
            MS++;
        }
    }

    cout<<"Number Of Pages HIT : " << HT<<endl ;
    cout<<"Number Of Pages MISS : " << MS<<endl ;
    cout<<"HIT Ratio : " << ((double)HT/n)*100<<"%"<<endl ;
    cout<<"MISS Ratio : " << ((double)MS/n)*100<<"%"<<endl ;

}