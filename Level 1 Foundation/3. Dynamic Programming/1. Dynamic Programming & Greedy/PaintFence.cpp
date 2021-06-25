#include<iostream>

using namespace std;

void solve(int n, int k)
{
    // here same, diff represents the number of ways the 'i' fences can be painted taking in considerations the constraints
    // such that 
    // same - latest 2 fences are same color
    // diff - latest 2 fences are of different color
    // the problem has base case for i=2

    int same = k * 1;
    int diff = k * (k-1);
    int total = same + diff;

    int i = 3;
    while(i<=n)
    {
        int nsame = diff * 1;          // only the previous 'diff' can be used as using 'same' will lead to 3 consicutive same colored fences
                                        // also we have only one choice of color to append at the end to make same 2 consicutive colored fences

        int ndiff = total * (k-1); // all the previous levels combinations can be used  and we can put any one of the remaining k-1 colors 
                                   // (other than the one at the end) to generate a new diff consicutive coloring


        i++;
        total = nsame + ndiff;
        same = nsame;
        diff = ndiff;
    }
    cout<<total;
}

int main()
{
    int n, k;
    cin>>n>>k;
    solve(n, k);
    return 0;
}