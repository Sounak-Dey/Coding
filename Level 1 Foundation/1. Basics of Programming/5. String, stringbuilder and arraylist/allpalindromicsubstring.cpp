#include <bits/stdc++.h>
using namespace std;


bool palindrome(string s)
{
    int l = 0;
    int r = s.length() - 1;

    while(l<=r)
    {
        if(s[l] != s[r])
            return false;
        else
        {
            l++;
            r--;
        }
    }

    return true;
}

void allPalindromeSubstring(string str)
{
    for(int i=0; i<str.size(); i++)
    {
        for(int j=1; j<=str.size()-i; j++)
        {
            string s = str.substr(i, j);
            if(palindrome(s) == true)
                cout<<s<<endl;
        }
    }
}

int main()
{
    string str;

    cin>>str;

    allPalindromeSubstring(str);

    return 0;
}