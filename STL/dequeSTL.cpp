#include <bits/stdc++.h>
using namespace std;

void printKMax(int arr[], int n, int k)
{
 //write your code here   

    vector<int> v;
    int i=0,j;
    
    while(k<=n)
    {
        for(j=i; j<k; j++)
        {
            v.push_back(arr[i]);
        }

        sort(v.begin(), v.end());
   
        cout<<v[k-1]<<" ";

        v.clear();
        i++;
        k++;
        
    }
    cout<<endl; 
}


//driver code
int main()
{
  
	int t;
	cin >> t;
	while(t>0) 
    {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
