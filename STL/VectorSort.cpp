#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    vector<int> v;
    int n,x;
    
    cin>> n;
    
    for(int i=0; i<n; i++){
        
        cin>>x;
        v.push_back(x);          
    }  
    
    sort(v.begin(), v.end());
    
    // vector printing method 1
    for(auto x : v)
        cout << x << " ";

    // Vector printing method 2
    // for(auto it=v.begin(); it!=v.end(); it++)
    // {
    //     cout<<*it<<" ";
    // }    

    return 0;
}