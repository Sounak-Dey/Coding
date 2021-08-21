#include<bits/stdc++.h>
using namespace std;

int solution(int n, int k)
{
    int survivor;

    if(n == 1)                          //if only one is left, then he is the survivor and he has position = 0;
        return 0; 

    survivor = solution(n-1, k);        //position of survivor from next stages;

    survivor = (survivor + k) % n;      //backtracking - by converting the position of survivor from next stages to his posiion in current stage; 

    return survivor;
}


int main()
{
    int n, k;
    cin>>n>>k;

    cout<<solution(n, k);

    return 0;
}