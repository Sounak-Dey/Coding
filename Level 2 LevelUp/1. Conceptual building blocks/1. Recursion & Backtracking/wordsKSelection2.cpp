#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;


void combination2(int idx, string ustr, int k, string asf)
{
    if(idx == ustr.length())
        return;
        
    if(k==0)
    {
        cout<<asf<<endl;
        return;
    }

    // options = characters
    // spots = levels
    for(int i = idx; i<ustr.length(); i++)
        combination2(i+1, ustr, k-1, asf + ustr[i]);
}

int main()
{
    string str;
    getline(cin, str);

    int k;
    cin>>k;

    unordered_set<char> unique;
    string ustr = "";

    for(auto ch: str)
        if(unique.find(ch) == unique.end())
        {
            unique.insert(ch);
            ustr += ch;
        }

    combination2(0, ustr, k, "");
    return 0;
}