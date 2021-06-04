#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,d;
    getline(cin,s);

    d = s[0];
    
    for(int i=1; i<s.length(); i++)
    { 
        d += to_string(s[i] - s[i-1]);
        d += s[i];
    }

    cout<<d<<endl;

    return 0;

}