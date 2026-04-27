// Question 12 — LRU Page Replacement
// Implement the Least Recently Used (LRU) page replacement algorithm.
// Display:
// •	frame status after each page reference 
// •	total page faults


// Input : 
// 12
// 2 3 2 1 5 2 4 5 3 2 5 2
// 3

#include<bits/stdc++.h>
using namespace std ;
 int main(){
    int n ; 
    
    cout<<"Enter Number of page : "<<endl ;
    cin>>n ;

    vector<int>page(n);
    cout<<"Enter Pages Sequence : "<<endl ;
    for(int i = 0 ; i < n ; i++){
        cin>>page[i];
    }

    cout<<"Enter Number of Frame : "<<endl ;   
    int f ;

    cin>>f;

    vector<int>frame;
    int HT= 0 , MS = 0;

    for(int i = 0 ; i < n ; i++){
        bool found = false;

        for(int j = 0 ; j < frame.size() ; j++){
            if(frame[j] == page[i]){
                found = true ;
                frame.erase(frame.begin() + j);
                frame.push_back(page[i]);
                break;
            }
        }

        if(found){
            HT++;
        }
        else{
            MS++;

            if(frame.size() < f){
                frame.push_back(page[i]);
            }
            else{
                frame.erase(frame.begin());
                frame.push_back(page[i]);
            }
        }
    }
    cout<<"\nNumber Of Pages HIT : " << HT<<endl;
    cout<<"Number Of Pages MISS : " << MS<<endl;
    cout<<"HIT Ratio : " << ((double)HT/n)*100<<"%"<<endl;
    cout<<"MISS Ratio : " << ((double)MS/n)*100<<"%"<<endl;

    return 0;


 }