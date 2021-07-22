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

void printSingleChildNodes(node *nd)
{
    if(nd == nullptr)
        return;

    if(nd->left == nullptr  &&  nd->right != nullptr) // 'nd' has single right child
        cout<<nd->right->data<<endl;

    else if(nd->left != nullptr  &&  nd->right == nullptr) // 'nd' has single left child
        cout<<nd->left->data<<endl;

    printSingleChildNodes(nd->left);
    printSingleChildNodes(nd->right);
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

    int lo, hi;
    cin>>lo>>hi;

    node *root = construct(arr);
    printSingleChildNodes(root);
    // display(root);
    
    return 0;
}
