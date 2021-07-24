/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    void pir(TreeNode *nd, int d1, int d2)
    {
        if(nd == nullptr)
            return;

        
        if(d1 < nd->val  &&  d2 < nd->val)
            pir(nd->left, d1, d2);
        
        else if(d1 > nd->val  &&  d2 > nd->val)
            pir(nd->right, d1, d2);
        
        else
        {
            pir(nd->left, d1, d2);
            sum += nd->val;
            pir(nd->right, d1, d2);
        }
    }
    
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        pir(root, low, high);
        return sum;
        
    }
};