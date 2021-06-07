#include <bits/stdc++.h>
using namespace std;

void printPermutations(string str, string asf)
{
    if(str.length() == 0)
    {
        cout<<asf<<endl;
        return;
    }

    for(auto i=0; i<str.length(); i++)
    {
        string temp = str;
        printPermutations(temp.erase(i,1), asf + str[i]);
        
        // another method to write
        // string remaining = str.substr(0,i) + str.substr(i+1);
        // printPermutations(remaining, asf + str[i]);
    }

}

int main()
{
    string str;
    cin>>str;
    printPermutations(str,"");

    return 0;
}