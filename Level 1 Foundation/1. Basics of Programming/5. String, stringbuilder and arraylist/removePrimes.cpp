#include <bits/stdc++.h>
using namespace std;

bool isPrime(int val)
{
    for(int div=2; div*div<=val; div++)
    {
        if(val % div == 0) 
            return false;
    }
    return true;
}

void removePrime(vector<int> &a)
{
    for(int i = a.size()-1; i>=0; i--)
    {
        if(isPrime(a[i]))
            a.erase(a.begin() + i);
    }
}

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0; i<n; i++)
        cin>>a[i];

    removePrime(a);
    
    cout<<"[";
    cout<<a[0];
    for(auto it=a.begin()+1; it!=a.end(); it++)
        cout<<", "<<*it;
    cout<<"]";

    return 0;
}