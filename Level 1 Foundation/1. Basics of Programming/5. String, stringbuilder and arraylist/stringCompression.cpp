#include <bits/stdc++.h>
using namespace std;

void compression1(string str)
{
    string s ;
    s = str[0];
    int j =0;

    for(int i=1; i<str.length(); i++)
    {
        if(str[i] != s[j])
        {
            s += str[i];
            j++;
        }
    }

    cout<<s<<endl;
    
}

void compression2(string str)
{
    string s;
    s = str[0];
    int count =1;

    for(int i=1; i<str.length(); i++)
    {
        if(str[i] == str[i-1])
            count++;
        else
        {
            if(count > 1)
            {
                s += to_string(count);
                count = 1;
            }
            s += str[i];
        }
            
    }

    if(count > 1)
        s += to_string(count);
    
    cout<<s<<endl;
}

int main()
{
    string str;

    getline(cin, str);

    compression1(str);
    compression2(str);

    return 0;
}