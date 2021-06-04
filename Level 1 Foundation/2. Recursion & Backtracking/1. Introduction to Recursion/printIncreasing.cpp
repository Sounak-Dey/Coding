#include <bits/stdc++.h>
using namespace std;

void printDecreasing(int n)
{
    if(n>0)
    {
        printDecreasing(n-1);
        cout<<n<<endl;
    }
    
}

int main()
{
    int n;
    cin >> n;
    printDecreasing(n);
    return 0;
}
