#include <bits/stdc++.h>
using namespace std;

static string codes[] = {",;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> kpc(string s)
{
    vector<string> v,r;

    if(s.length() == 0)
    {
        r.push_back("");
        return r;
    }

    v = kpc(s.substr(1));

    int n = s[0] - '0';
    string k = codes[n];

    for(int i=0; i<k.length(); i++)
    {
        for(auto j: v)
        {
            r.push_back(k[i] + j);
        }
    }

    return r;
}


int main()
{
    string s;
    cin >> s;
    vector<string> ans = kpc(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';

    return 0;
}