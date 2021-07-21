#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    
    vector<TreeNode *> nodeToRootPath(TreeNode *nd, TreeNode *data)
    {
        vector<TreeNode *> path;

        if(nd == nullptr)
            return path;

        if(nd == data)
            path.push_back(nd);

        else if(nodeToRootPath(nd->left, data).size() > 0 ) // if data found in left subtree so it returns a filled vector
        {
            path = nodeToRootPath(nd->left, data);
            path.push_back(nd);
        }
        else if(nodeToRootPath(nd->right, data).size() > 0 ) // if data found in right subtree
        {
            path = nodeToRootPath(nd->right, data);
            path.push_back(nd);
        }

        return path;
    }

    void printKLevelsDown(TreeNode *nd, int k, TreeNode *blocker)
    {
        if(nd == nullptr || k < 0  ||  nd == blocker)
            return;

        if(k==0)
        {
            ans.push_back(nd->val);
            return;
        }

        printKLevelsDown(nd->left, k-1, blocker);
        printKLevelsDown(nd->right, k-1, blocker);
    }

    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        vector<TreeNode*> path = nodeToRootPath(root, target);
        
        printKLevelsDown(path[0], k, nullptr);

        for(int i=1; i<path.size(); i++)
            printKLevelsDown(path[i], k-i, path[i-1]);
        
        return ans;
    }
};