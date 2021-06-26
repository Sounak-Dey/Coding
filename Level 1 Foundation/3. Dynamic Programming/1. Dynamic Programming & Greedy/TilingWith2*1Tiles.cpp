#include<iostream>

using namespace std;

int solve(int n)
{
    int prevn, prev2n;

    //base case
    prev2n = 1;     //stores number of ways we can arrange in 2 * i-2 space, base case 1
    prevn = 2;      //stores number of ways we can arrange in 2 * i-1 space, base case 2
    int currn;      //stores number of ways we can arrange in 2 * i space

    int i = 3;
    while(i++<=n)
    {
        currn = prevn + prev2n;

        prev2n = prevn;
        prevn = currn;
    }
    cout<<currn;
}

int main()
{
    int n;
    cin>>n;
    solve(n);
    return 0;
}