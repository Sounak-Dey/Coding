#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<queue>

using namespace std;

//structure of a node of the tree
struct node
{
    int data;
    vector<node *> children; 
                             
};


//diplay the tree
void display(node *nd)
{
    string str = to_string(nd->data) + " -> ";  

    for(auto child: nd->children)       
        str += to_string(child->data) + ", ";  

    str += ".";
    cout<<str<<endl;

    for(auto child: nd->children)   
        display(child);
}


//construct a tree from an array using Left to Right - Depth First Search
node *construct(vector<int> arr)
{
    node *root = nullptr;
    stack<node *> st;       

    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == -1)    
            st.pop();
        
        else        
        {
            node *t = new node();       
            t->data = arr[i];           

            if(st.empty())      
                root = t;
            else
                st.top()->children.push_back(t);                         
            
            st.push(t);     
        }
    }

    return root;
}

int maxSum;
int maxSumNode;

int sum(node *nd)
{
    int sumn = nd->data; // sumn = the value of the sum of the subtree of node 'nd'

    for(auto child: nd->children) // adding sum of subtrees of its children using recursion
        sumn += sum(child); 


    if(sumn > maxSum)
    {
        maxSum = sumn;
        maxSumNode = nd->data;
    }

    return sumn;    // we don't return the maxsum of a subtree with nd as root because it won't allow us to calculate the actual sum of the subtree, it will be = maxsubtree sum + node value
}                   // and not sum of subtree + node value, which is what we actually need to calculate the maxSum.

int main()
{
    int n1;
    cin>>n1;
    vector<int> arr1(n1);
    for(auto &i: arr1)
        cin>>i;

    node *root = construct(arr1);
    maxSum = INT32_MIN;
    sum(root);
    cout<<maxSumNode<<"@"<<maxSum<<endl;

    return 0;
}