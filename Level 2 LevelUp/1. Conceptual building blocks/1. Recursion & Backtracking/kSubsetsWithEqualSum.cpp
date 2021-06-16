#include<iostream>
#include<string>
#include<vector>

using namespace std;

void display(vector<vector<int>> &ans)
{

    for(auto i=0; i<ans.size(); i++)
    {                                               
        cout<<"[";
        for(auto j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j];
            if(j < ans[i].size()-1) 
                cout << ", ";
        }
        cout<<"] ";     
    }
    cout<<endl; 
}


void solution(vector<int> &arr, int idx, int n , int k, vector<int> &subsetSum, int partitionCount, vector<vector<int>> &ans)
{

    if(idx == n)
    {
        if(partitionCount == k )
        {
            for(int i=1; i<k; i++)                      //checking if sum of all partitions are equal
                if(subsetSum[i] != subsetSum[i-1])
                    return;

            display(ans);
        }
        return;
    }

    //loop through all the partition sets
    for(auto r=0; r<k; r++)
    {
        if(ans[r].size() > 0)       // placing idx'th number in a non-empty partition
        {
            subsetSum[r] += arr[idx];
            ans[r].push_back(arr[idx]);
            solution(arr, idx+1, n, k, subsetSum, partitionCount, ans);
            ans[r].pop_back();
            subsetSum[r] -= arr[idx];
        }
        else if(ans[r].size() == 0)     // placing idx'th number  in an empty partition
        {
            subsetSum[r] += arr[idx];
            ans[r].push_back(arr[idx]);       
            solution(arr, idx+1, n, k,subsetSum, partitionCount + 1, ans);
            ans[r].pop_back();
            subsetSum[r] -= arr[idx];
            break;
        }  
    }
}



int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    int sum = 0;
    for(int i=0; i<n, i++)
    {
        cin>>arr[i];
        sum += arr[i];
    }
    int k;
    cin>>k;

    // if k is equal to 1, then whole array is your answer
    if(k == 1)
    {
        cout<<"[";
        for(int i=0; i<n; i++)
            cout<<arr[i] + ", " ;

        cout<<"]" ;
        return 0;
    }

    //if there are more subsets than no. of elements in array 
    //or sum of all elements is not divisible by k
    if(k>n || sum%k != 0)
    {
        cout<<"-1";
        return 0;
    }

    vector<int> subsetSum(k, 0);
    vector<vector<int>> ans(k);

    solution(arr, 0, n, k, subsetSum, 0, ans);

    return 0;
}

