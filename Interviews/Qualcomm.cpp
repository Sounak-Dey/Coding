
#include<iostream>
using namespace std;

node *head;
void inorder(node *curr)
{
    static node *pred = nullptr;
    
    if(curr == nullptr)
        return 


    inorder(nd->left)

    //work
    if(pred == nullptr)
    {
        head = curr;
    }
    else
    {
        curr->left = pred;
        pred->right = curr;
    }
    pred = curr;

    inorder(curr->right)
}

int main()
{
    
}
