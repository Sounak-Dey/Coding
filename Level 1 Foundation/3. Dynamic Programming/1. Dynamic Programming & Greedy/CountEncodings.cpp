#include<iostream>
#include<string>
#include<vector>

using namespace std;

void solve(string str)
{
    int n =str.length();
    vector<int> dp(n);
    //dp[i] stores the count of encoding possible till ith index of string

    dp[0] = 1;

    for(int i=1; i<n; i++)
    {
        if(str[i-1] == '0'  &&  str[i] == '0')  //can neither go solo nor duo
        {
            dp[i] = 0;      // no encodings possible
        }
        else if(str[i-1] == '0'  &&  str[i] != '0')  //can only go solo
        {
            dp[i] = dp[i-1];        //add str(i)'s encoding to the previous encodings
        }   
        else if(str[i-1] != '0'  &&  str[i] == '0') // can only be considered in duo
        {                   
            if(str[i-1] <= '2')  // otherwise duo will become greater than 26
            {
                if(i-2 >= 0)  // to check for out of bounds
                    dp[i] = dp[i-2];
                else
                    dp[i] = 1;
            }
        }
        else if(str[i] != '0'  &&  str[i-1] != '0')
        {
            if(stoi( str.substr(i-1, 2) ) <= 26) // add counts of both considering as a solo
            {                                   // as well as duo 
                if(i-2 >= 0)
                    dp[i] = dp[i-1] + dp[i-2] ;
                else
                    dp[i] = dp[i-1] + 1;
            }
            else                            // add count of only solo
                dp[i] = dp[i-1];
        }
    }

    cout<<dp[n-1];
}   

int main()
{
    string str;
    cin>>str;
    solve(str);
    return 0;
}