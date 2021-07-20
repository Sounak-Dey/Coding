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

void iterativePrePostInTraversal(node *root)
{
    if(root == nullptr) // if tree is empty
        return;


    stack<pair<node*, int>> st;
    string pre = "";
    string in = "";
    string post = "";
    st.push({root, 1});

    while(!st.empty())
    {   
        if(st.top().second == 1) // when state = 1, preorder
        {
            pre += to_string(st.top().first->data) + " ";
            st.top().second++;
            
            if(st.top().first->left != nullptr)     // push left child if not nullptr
                st.push({st.top().first->left, 1}); 
        }
        else if(st.top().second == 2) // state == 2, inorder
        {
            in += to_string(st.top().first->data) + " ";
            st.top().second++;
            
            if(st.top().first->right != nullptr)    //push right child if not nullptr
                st.push({st.top().first->right, 1});
        }
        else    //state == 3, postorder visit
        {
            post += to_string(st.top().first->data) + " ";
            st.pop();   // exploring the node fully completed, pop()
        }
    }

    cout<<pre<<endl;
    cout<<in<<endl;
    cout<<post<<endl;
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
    iterativePrePostInTraversal(root);
    
    return 0;
}
