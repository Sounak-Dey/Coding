#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    vector<int> v;
    int n,p,x,a,b;
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        v.push_back(x);
    }
    
    cin>>p;
    v.erase(v.begin()+p-1);
     
    cin>>a>>b;
    v.erase(v.begin()+a-1,v.begin()+b-1);
    
    cout<<v.size()<<endl;
    for(auto x:v)
        cout<<x<<" ";
    
    return 0;
}
