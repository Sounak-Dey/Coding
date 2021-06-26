#include<iostream>

using namespace std;

int solve(int n)
{
    //base cases
    int prev2n = 1; //when i=1
    int prevn = 2;  // when i=2
    int currn;

    // here fn = curr represents the total count if curr 'i' stays single or pairs up
    // fn-1 = prevn represents the same for i-1
    // fn-2 = prev2n represents the same for i-2
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