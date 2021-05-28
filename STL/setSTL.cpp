#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    set<long long> s;
    int q, y;
    long long x;
    
    cin>>q;
    
    while(q){

        cin>>y;
        
        if(y==1)
        {
            cin>>x;
            s.insert(x);
        }
        else if(y==2)
        {
            cin>>x;
            s.erase(x);
        }
        else if(y==3)
        {
            cin>>x;
            set<long long>:: iterator i;
            i = s.find(x);
            
            if(i == s.end())
            {
                cout<<"No"<<endl;
            }
            else
                cout<<"Yes"<<endl;
        }
        
        q--;

    }

    return 0;
}