#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(string s)
{
    for(int i=0, j=s.length()-1; i<j; i++, j--)
        if(s[i] != s[j])
            return false;

    return true;
}


void solution(string str, string asf)
{
    if(str.length() == 0)
    {
        cout<<asf<<endl;
        return;
    }    

    for(auto i=1; i<=str.length(); i++)     // here i = prefix length
    {
        string prefix = str.substr(0,i);
        
        if(isPalindrome(prefix))
            solution(str.substr(i), asf + "(" + prefix + ") ");
    }
}

int main()
{
    string str;
    cin>>str;

    solution(str, "");

    return 0;
}