#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
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

node *construct(vector<int> &arr)
{
    node *root = new node(arr[0], nullptr, nullptr);
    
    stack<pair<node *, int>> st; 
    st.push({root, 1}); // st.top().second represents the state in which, the node represented by st.top().first is in
    int idx = 1;

    while(!st.empty())
    {
        if(st.top().second == 1) // state = 1 means visiting for adding left child
        {
            if(arr[idx] == NULL) // if left child is null
            {
                st.top().second++;  // st.top().first->left = nullptr; not needed as when we had created this node previously, we already set its both children as nullptr by default
            }
            else    // if left child exists
            {
                node *n = new node(arr[idx], nullptr, nullptr);
                st.top().first->left = n;
                st.top().second++;
                st.push({n, 1});
            }
            idx++;
        }
        else if(st.top().second == 2)   // state = 2 means visiting for ading right child
        {
            if(arr[idx] == NULL)
            {
               st.top().second++;
            }
            else
            {
                node *n = new node(arr[idx], nullptr, nullptr);
                st.top().first->right = n;
                st.top().second++;
                st.push({n, 1});
            }
            idx++;
        }
        else    // state = 3 means both children have been added, pop the stack top node
        {
            st.pop();
        }
    }
    
    return root;
}

void display(vector<int>& arr)
{
    cout << "[";
    for(int i=0; i < arr.size(); i++)
    {
        cout << arr[i];
        if(i < arr.size() -1) 
            cout << ", ";
    }
    
    cout << "]"<<endl;
}

struct triad
{
    bool BST;
    int nmin;
    int nmax;
};

triad *isaBST(node *nd)
{
    triad *ret = new triad();

    if(nd == nullptr) // base case
    {
        ret->BST = true;
        ret->nmin = INT32_MAX; // identity of min
        ret->nmax = INT32_MIN; // identity of max
        return ret;
    }

    triad *l = isaBST(nd->left);
    triad *r = isaBST(nd->right);

    if(l->nmax < nd->data  &&  nd->data < r->nmin  && l->BST == true  &&  r->BST == true) // global BST cannot be used, as nd->left's result gets overwritten by nd->right
        ret->BST = true;
    else
        ret->BST = false;
    
    ret->nmin = min(l->nmin, nd->data); // basically a hacky to handle leaf nodes, when nd->data needs to be returned
    ret->nmax = max(r->nmax, nd->data); // else generally l.first and r.second represent the min and max values in a subtree

    return ret;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    string c;
    for(auto &x: arr)
    {
        cin>>c;
        if(isdigit(c[0]))
            x = stoi(c);
        else
            x = NULL;
    }

    node *root = construct(arr);

    triad *t = isaBST(root);

    if(t->BST == true)
        cout<<"true";
    else
        cout<<"false";
    
    return 0;
}