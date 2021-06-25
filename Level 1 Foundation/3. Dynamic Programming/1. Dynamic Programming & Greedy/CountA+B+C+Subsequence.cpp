#include<iostream>

using namespace std;

void solve(string str)
{
    int a = 0;      //count of subsequences of the form a+
    int ab = 0;     //count of subsequences of the form a+b+
    int abc = 0;    //count of subsequences of the form a+b+c+

    int i=0;
    while(i<str.length())
    {
        if(str[i] == 'a')
            a = 2*a + 1;
        else if(str[i] == 'b')
            ab = 2*ab + a;
        else if(str[i] == 'c')
            abc = 2*abc + ab;
        
        i++;
    }
    cout<<abc;
}

int main()
{
    string str;
    cin>>str;
    solve(str);
    return 0;
}