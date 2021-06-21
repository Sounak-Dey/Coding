#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

// levels - characters
//options - spots
// levels > options
// so levels/characters have a choice of choosing a spot or not appearing at all
void solution(string ustr, int placed, int k, vector<char> &spots)
{
    if(placed == k)
    {
        for(auto ch: spots)
            cout<<ch;

        cout<<endl;
        return;
    }

    if(ustr.length() == 0) //ustr.length() can reach 0 before all the spots are filled
        return;

    for(int i=0; i<k; i++)
    {
        if(spots[i] == '0')
        {
            spots[i] = ustr[0];
            solution(ustr.substr(1), placed+1, k, spots);
            spots[i] = '0';
        }
    }
    solution(ustr.substr(1), placed, k, spots);
}


int main()
{
    string str, ustr = "";
    cin>>str;
    int k;
    cin>>k;

    unordered_set<char> unique;
    for(auto ch: str)
        if(unique.find(ch) == unique.end())
        {
            unique.insert(ch);
            ustr += ch;
        }
    
    vector<char> spots(k,'0');
    solution(ustr,0, k, spots);
    return 0;
}