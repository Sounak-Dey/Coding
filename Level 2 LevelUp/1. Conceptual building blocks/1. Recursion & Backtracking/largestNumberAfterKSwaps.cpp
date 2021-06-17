#include<iostream>
#include<string>

using namespace std;

string max = to_string(INT32_MIN);

void swap(string &str, int i, int j)
{
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void findMaximum(string &str, int k)
{
    if(stoi(str) > stoi(::max))
        ::max = str;

    if(k == 0)
        return;

    for(int i=0; i<str.length()-1; i++)
        for(int j=i+1; j<str.length(); j++)
            if(str[j] > str[i])             //swapping only if jth character is greater than ith character
            {
                swap(str, i, j);
                findMaximum(str, k-1);
                swap(str, i, j);
            }
}

int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;

    ::max = str;
    findMaximum(str, k);
    cout<<::max;
    return 0;
}