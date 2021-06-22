#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;


void combination2(unordered_set<string> &unique, int idx, string ustr, int k, string asf)
{
    if(idx == ustr.length())
        return;
        
    if(k==0)
    {
        if(unique.find(asf) == unique.end())
        {
            unique.insert(asf);
            cout<<asf<<endl;
        }
        return;
    }

    // options = characters
    // spots = levels
    for(int i = idx; i<ustr.length(); i++)
        combination2(unique, i+1, ustr, k-1, asf + ustr[i]);
}

int main()
{
    string str;
    getline(cin, str);

    int k;
    cin>>k;

    unordered_set<string> unique;
    combination2(unique, 0, str, k, "");
    return 0;
}