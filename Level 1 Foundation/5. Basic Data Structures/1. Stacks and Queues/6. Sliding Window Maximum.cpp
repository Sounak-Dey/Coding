#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<cstdint>

using namespace std;

void solve(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> nger(n);

    stack<int> st;
    st.push(n-1);   //stores index
    nger[n-1] = INT32_MAX; //stores index

    for(int i=n-2; i>=0; i--)
    {
        while(st.size() > 0  &&  arr[i] >= arr[st.top()]) 
            st.pop();

        if(st.empty())   
            nger[i] = INT32_MAX;
        else                
            nger[i] = st.top();

        st.push(i);     
    }

    for(int i=0, j=0; i<=n-k; i++)
    {
        if(j<i)
            j=i;
        
        while(nger[j] < i+k) // if (nger[j] > i+k), it will mean nger[j] is the biggest element in the curr window
            j = nger[j];
        
        cout<<arr[j]<<endl;
    }
}



int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr)
        cin>>i;
    int k;
    cin>>k;

    solve(arr, k);
    return 0;
}