#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

string ans = "";
int mindiff = INT32_MAX;

string display(vector<int>& arr)
{
    string disp = "";
    disp += "[";
    for(int i = 0;i < arr.size();i++)
    {
        disp += to_string(arr[i]);
        if(i < arr.size() -1) disp += ", ";
    }
    
    disp += "]";

    return disp;
}

void solve(vector<int> &arr, int idx, vector<int> &set1, vector<int> &set2, int &sumSet1, int &sumSet2)
{
    if(idx == arr.size())
    {
        int diff = abs(sumSet1 - sumSet2);

        if(diff < mindiff)
        {
            mindiff = diff;
            ans = display(set1) + " " + display(set2);
        }    
    }


    //when add to set1
    if(set1.size() < (arr.size()+1)/2)      //bounded by max possible set size
    {
        set1.push_back(arr[idx]);
        sumSet1 += arr[idx];
        solve(arr, idx+1, set1, set2, sumSet1, sumSet2);
        sumSet1 -= arr[idx];
        set1.pop_back();
    }

    // set2
    if(set2.size() < (arr.size()+1)/2)      //bounded by max possible set size
    {
        set2.push_back(arr[idx]);
        sumSet2 += arr[idx];
        solve(arr, idx+1, set1, set2, sumSet1, sumSet2);
        sumSet2 -= arr[idx];
        set2.pop_back();
    }
    

}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    vector<int> set1, set2;
    int sumSet1=0, sumSet2=0;

    solve(arr, 0, set1, set2, sumSet1, sumSet2);

    cout<<ans;
    return 0;
}