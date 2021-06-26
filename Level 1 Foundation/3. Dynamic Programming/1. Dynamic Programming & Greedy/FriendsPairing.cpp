#include<iostream>

using namespace std;

int solve(int n)
{
    int prev2n = 1;
    int prevn = 2;
    int currn;

    // here fn = curr represents the total count if curr stays single or pairs up
    // fn = fn-1 * (n-1)*fn-2; 
    int i = 3;
    while(i<=n)
    {
        currn = prevn + (i-1) * prev2n;

        i++;
        prev2n = prevn;
        prevn = currn;
    }
    cout<<currn;
    return 0;
}

int main()
{
    int n;
    cin>> n;
    solve(n);
    return 0;
}