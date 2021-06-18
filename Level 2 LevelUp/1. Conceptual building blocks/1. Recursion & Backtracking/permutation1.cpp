#include<iostream>
#include<vector>

using namespace std;

// ci - current item/r
void permutations1(vector<int> &boxes, int ci, int r)
{
    //levels - r
    //options - boxes

    if(ci > r)
    {
        for(int i=0; i<boxes.size(); i++)
            cout<<boxes[i];
        cout<<endl;
        return;
    }

    for(int i=0; i<boxes.size(); i++)
        if(boxes[i] == 0)
        {
            boxes[i] = ci;
            permutations1(boxes, ci+1, r);
            boxes[i] = 0;
        }
}


int main()
{
    int n, r;
    cin>>n>>r;

    vector<int> boxes(n, 0);

    permutations1(boxes, 1, r);

    return 0;

}