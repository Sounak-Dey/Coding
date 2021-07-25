#include<bits/stdc++.h>
using namespace std;

void lcse(vector<int> &a)
{
    unordered_map<int, bool> boolMap;

    for(auto i: a)
        boolMap[i] = true;
    
    for(auto i: a)
    {
        if(boolMap.find(i-1) != boolMap.end())
            boolMap[i] = false;
    }

    int msp = 0;
    int ml = 0;
    for(auto i: boolMap)// this fails during conflicts
    {
        if(i.second == true)
        {
            int tl = 1;
            int tsp = i.first;

            while(boolMap.find(tsp + tl) != boolMap.end())
                tl++;
            
            if(tl > ml)
            {
                msp = tsp;
                ml = tl;
            }
        }
    }

    for(int i=0; i<ml; i++)
        cout<<msp+i<<endl;
}


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);
    for(auto &x: a)
        cin>>x;
    
    lcse(a);

    return 0;
}