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

int size(node *nd)
{
    // if(nd == nullptr)    //not needed
    //     return 0;        

    int count = 0;
    for(auto child: nd->children)
        count += size(child);

    return count + 1;
}

int maxv(node *nd)
{
    int m = nd->data;
    for(auto child: nd->children)
        m = max(m, maxv(child));

    return m;
}

int height(node *nd)
{
    int h = 0;
    for(auto child: nd->children)
        h = max(h, height(child) + 1); // since height is calculated using edges, & edge exists only if child exists

    return h;
}

void traversals(node *nd)
{
    cout<<"Node Pre "<<nd->data<<endl;

    for(auto child: nd->children)
    {
        cout<<"Edge Pre "<<nd->data<<"--"<<child->data<<endl;
        traversals(child);
        cout<<"Edge Post "<<nd->data<<"--"<<child->data<<endl;
    }

    cout<<"Node Post "<<nd->data<<endl;
}

void levelOrder(node *root)
{
    queue<node *> q;
    q.push(root);

    while(!q.empty())
    {
        cout<<q.front()->data<<" ";
        
        for(auto child: q.front()->children)
            q.push(child);

        q.pop();
    }

    cout<<".";
}

void levelOrderLineWise(node *root)
{
    queue<node*> parentq, childq;
    parentq.push(root);

    while(!parentq.empty()  ||  !childq.empty())
    {
        if(parentq.empty())
        {
            cout<<endl;
            swap(parentq, childq);
        }

        cout<<parentq.front()->data<<" ";

        for(auto child: parentq.front()->children)
            childq.push(child);
        
        parentq.pop();
    }
}

void levelOrderLineWiseZZ(node *root)
{
    stack<node*> parentSt, childSt;
    parentSt.push(root);
    int childLevel = 1;

    while(!parentSt.empty()  ||  !childSt.empty())
    {
        if(parentSt.empty())
        {
            cout<<endl;
            parentSt = childSt;
            childSt = {};
            childLevel++;
        }

        cout<<parentSt.top()->data<<" ";

        if(childLevel%2 == 1) // add children in right to left order
        {
            for(int i=0; i<parentSt.top()->children.size(); i++)
                childSt.push(parentSt.top()->children[i]);
        }
        else    // add children in left to right order
        {
            for(int i=parentSt.top()->children.size() - 1; i>=0; i--)
                childSt.push(parentSt.top()->children[i]);
        }
        
        parentSt.pop();
    }
}

void mirror(node *nd)
{
    reverse(nd->children.begin(), nd->children.end());

    for(auto child: nd->children)
        mirror(child);
}

void removeLeaves(node *nd)
{
    for(int i=nd->children.size() - 1; i>=0; i--) // right to left as when we erase the elements shift forward, so we might skip
    {
        node *child = nd->children[i];
        if(child->children.size() == 0)
            nd->children.erase(nd->children.begin() + i);
    }

    for(auto child: nd->children)
        removeLeaves(child);
}


int main() 
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr)
        cin>>i;
    
    node *root = construct(arr);
    removeLeaves(root);
    display(root);

    return 0;
}