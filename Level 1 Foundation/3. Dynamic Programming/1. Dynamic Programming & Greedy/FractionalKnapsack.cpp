#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int solve(vector<int> &weight,  vector<int> &value, int cap)
{
    map<double, int> imap;

    for(int i=0; i<weight.size(); i++)
    {
        imap[weight[i] / value[i]] = i;     //this gets rounded of to zero
    }

    int currentWeight = 0;
    double currentValue = 0;
    int idx;

    for(auto x: imap)
    {
        if(currentWeight + weight[x.second]  <= cap)
        {
            currentValue += value[x.second];
            currentWeight += weight[x.second];
        }
        else
        {
            idx = x.second;
            break;
        }
    }

    int remCap = cap - currentWeight;

    double val = (remCap / weight[idx] ) * value[idx];
    currentValue += val;

    cout<<currentValue;

    return 0;
}

int main()
{
    int n;
    cin>>n;

    vector<int> value(n), weight(n);
    for(int i=0; i<n; i++)
        cin>>value[i];
    for(int i=0; i<n; i++)
        cin>>weight[i];
        
    int cap;
    cin>>cap;

    solve(weight, value, cap);

    return 0;
}