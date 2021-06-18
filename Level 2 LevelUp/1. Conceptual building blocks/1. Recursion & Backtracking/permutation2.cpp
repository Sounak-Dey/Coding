#include<iostream>
#include<vector>

using namespace std;

//bi = box index
// r = total items to be placed i.e options
// ru = items remaining to be placed
// options = true if this ith item has already been used
void permutations2(vector<int> &boxes,int bi, int r, int ru, vector<bool> &options)
{

    if(bi == boxes.size())
    {
        if(ru == 0)
        {
            for(int i=0; i<boxes.size(); i++)
                cout<<boxes[i];
            cout<<endl;
        }
        return;
    }

    // levels - boxes
    // options - r
    
    for(int i=1; i<=r; i++)
    {
        if(options[i] == false)
        {
            options[i] = true;
            boxes[bi] = i;
            permutations2(boxes, bi+1, r, ru-1, options);
            boxes[bi] = 0;
            options[i] = false;
        }
    }
    permutations2(boxes, bi+1, r, ru, options);
}


int main()
{
    int n, r;
    cin>>n>>r;
    
    // string boxes(n, '-');
    vector<int> boxes(n, 0);
    vector<bool> options(r+1, false);

    permutations2(boxes, 0, r, r, options);

    return 0;
}