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

int diameter = INT32_MIN;
int deepestChildHeight(node *nd)
{
    int dch = -1; // -1 beacuse for leaf node it will return dch + 1 = 0
    int sdch = -1;
    for(auto child: nd->children)
    {
        int height = deepestChildHeight(child);

        if(height > dch)
        {
            sdch = dch;
            dch = height;
        }
        else if(height > sdch)
        {
            sdch = height;
        }
    }

    if(dch + sdch + 2  >  diameter) // calculates dch+sdch+2 for every node and stores the max value in diameter
        diameter = dch + sdch + 2;  // because it is not necessary that the diameter passes through the root node
    
    return dch + 1; // returns height of the node
}


int main()
{
    int n1;
    cin>>n1;
    vector<int> arr1(n1);
    for(auto &i: arr1)
        cin>>i;

    node *root = construct(arr1);
    
    deepestChildHeight(root);
    cout<<diameter<<endl;

    return 0;
}