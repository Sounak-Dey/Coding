#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int data, node *left, node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};


void display(node *nd)
{
    if(nd == nullptr)
        return;


    string str = "";

    str += (nd->left == nullptr) ? "." : to_string(nd->left->data);
    str += " <- " + to_string(nd->data) + " -> ";
    str += (nd->right == nullptr) ? "." : to_string(nd->right->data);
    
    cout<<str<<endl;

    display(nd->left);
    display(nd->right);
}

node *construct(vector<int> &arr, int lo, int hi)
{
    if(lo > hi)
        return nullptr;

        
    int mid = (lo + hi) /2;
    int data = arr[mid];

    node *left = construct(arr, lo, mid - 1);
    node *right = construct(arr, mid + 1, hi);

    node *nd = new node(data, left, right);

    return nd; 
}


int main()
{
    vector<int> arr{12, 25, 37, 50, 62, 75, 87};
    node *root = construct(arr, 0, arr.size()-1);
    display(root);
    
    return 0;
}
