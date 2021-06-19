
// taking characters as levels ans spots as options
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

void pw2(int cc, string str,  vector<char> &spots, unordered_map<char, int> &lastOccurance)
{
    if(cc == str.length())
    {
        for(int i=0; i<spots.size(); i++)
            cout<<spots[i];
        cout<<endl;
        return;
    }
    
    int lo = lastOccurance[str[cc]]; // to remove permutations within characters appearing multiple times

    for(int i=lo+1; i<spots.size(); i++)
        if(spots[i] == '0')
        {
            lastOccurance[str[cc]] = i;
            spots[i] = str[cc];
            pw2(cc+1, str, spots, lastOccurance);
            spots[i] = '0';
            lastOccurance[str[cc]] = lo;
        }
}


int main()
{
    string str;
    getline(cin, str);

    vector<char> spots(str.length(), '0');
    unordered_map<char, int> lastOccurance;

    for(int i=0; i<str.length(); i++)       // initiates all characters last appearance as -1
        lastOccurance[str[i]] = -1;

    pw2(0, str, spots, lastOccurance);
    return 0;
}