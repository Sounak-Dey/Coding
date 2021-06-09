#include <bits/stdc++.h>
using namespace std;

int fib(int n, vector<int> &mem)
{
    if(n==0 || n==1)
        return n;

    if(mem[n] != 0)
        return mem[n];

    mem[n] = fib(n-1, mem) + fib(n-2, mem);

    return mem[n];
}

int main()
{
    int n;
    cin>>n;

    vector<int> mem(n+1, 0);

    cout<<fib(n, mem)<<endl;

    return 0;
}