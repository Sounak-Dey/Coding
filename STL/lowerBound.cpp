#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    vector<long long unsigned int> v;
    int n,q;
    long long unsigned int x,y;
      
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        v.push_back(x);
    }  
      
    cin>>q;  
    while(q){
        cin>>y;
        
        vector<long long unsigned int>::iterator l;
        
        l = lower_bound(v.begin(), v.end(), y);
        int index = l - v.begin() ;
        
        if(v[index] == y)
            cout<<"Yes "<<index+1<<endl;
        else 
            cout<<"No "<<index+1<<endl;    
      
        q--;
    }  
      
    return 0;
}