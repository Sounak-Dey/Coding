#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

void generatepw(int cs, int ts, unordered_map<char, int> &freqMap, char oddc, string asf)
{
    if(cs > ts)
    {
        string result = asf;

        if(oddc != '0')
            result += oddc;

        for(int i = asf.length()-1; i>=0; i--)
            result += asf[i];

        cout<<result<<endl;

        return;
    }

    //permutations of the string
    for(auto x: freqMap)
        if(x.second > 0)
        {
            freqMap[x.first]-- ;
            generatepw(cs+1, ts, freqMap, oddc, asf + x.first);
            freqMap[x.first]++ ;
        }
}



int main()
{
    string str;
    cin>>str;
    unordered_map<char, int> freqMap;

    for(int i=0; i<str.length(); i++)   //calculating frequency of each character in string
        freqMap[str[i]]++ ;             
    
    char odd = '0';
    int odds = 0, len = 0;

    for(auto &x: freqMap)
    {
        if(x.second % 2 == 1)       // finding the characters with odd freq
        {
            odd = x.first;
            odds++;
        }

        freqMap[x.first] = x.second / 2;    //halfing the freq of each charachter
        len += x.second;                // new length of the halfed string
    }

    if(odds > 1)
        cout<< -1;
    else
        generatepw(1, len, freqMap, odd, "");
    
    return 0;
}