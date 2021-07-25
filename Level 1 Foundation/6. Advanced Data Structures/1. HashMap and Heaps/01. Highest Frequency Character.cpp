#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

char hfc(string str)
{
    unordered_map<char, int> fmap;

    for(auto x: str) // calculating freq of characters
        fmap[x]++;

    int maxv = INT32_MIN;
    char maxc;

    for(auto i: fmap)
    {
        if(i.second > maxv) //finding max freq character
        {
            maxv = i.second;
            maxc = i.first;
        }    
    }
        
    return maxc;
}


int main()
{
    string str;
    getline(cin, str);

    cout<<hfc(str);
    return 0;
}
