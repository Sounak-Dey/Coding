#include <bits/stdc++.h>
using namespace std;

long long factorial(int n)
{
    long long f = 1;

    for(int i=1; i<=n; i++)
        f *= i;
        
    return f;
}

void permute(string s)
{
    long long f = factorial(s.length());

    for(int i=0; i<f; i++)
    {
        string p = s;
        int t = i;

        for(int div = s.length(); div>0; div--)
        {
            int r = t % div;

            cout<<p[r];
            p.erase(r,1);

            t = t/div;
        }

        cout<<endl;
    }
}


int main()
{
    string str;
    getline(cin,str);

    permute(str);

    return 0;
}