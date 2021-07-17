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

node *getTail(node *nd)
{
    while(!nd->children.empty())
        nd = nd->children[0];
    
    return nd;
}

void linearize(node *nd)
{
    for(auto child: nd->children)   // linearize indivisual child using recursion
        linearize(child);
    
    while(nd->children.size() > 1)
    {
        node *lastChild = nd->children[nd->children.size()-1];    // get the last child of 'nd'
        nd->children.erase(nd->children.begin() + nd->children.size()-1); // remove the last child

        node *secondLast = nd->children[nd->children.size()-1]; // second last child is nor last child
        node *secondLastsTail = getTail(secondLast);    
        secondLastsTail->children.push_back(lastChild); // add last child as a child to the tail of the second last child
    }
}


int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr)
        cin>>i;
    
    node *root = construct(arr);
    linearize(root);
    display(root);

    return 0;
}