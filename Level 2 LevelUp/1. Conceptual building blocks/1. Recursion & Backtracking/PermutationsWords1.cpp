
// this maintaining a frequence map removes the possibility of printing two same permutations that 
// get generated when multiple same characters are present in the words/string

#include<iostream>
#include<string>
#include<map>

using namespace std;

//bi = box index
//tb = total boxes
void pw1(int bi, int tb, map<char, int> &freqMap, string asf)
{
    if(bi == tb)
    {
        cout<<asf<<endl;
        return;
    }

    for( auto &i: freqMap)
        if(freqMap[i.first] > 0)
        {
            freqMap[i.first]--;
            pw1(bi+1, tb, freqMap, asf + i.first);
            freqMap[i.first]++;
        }
}


int main()
{
    string str;
    getline(cin, str);

    map<char, int> freqMap;
    for(int i=0; i<str.length(); i++)   //calculating frequency of each character in string
        freqMap[str[i]]++ ; 

    pw1(0, str.size(), freqMap, "");
    return 0;

}