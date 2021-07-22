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
    
    struct triad
    {
        bool BST;
        long int nmin;
        long int nmax;
    };

    triad isaBST(TreeNode *nd)
    {
        triad ret;

        if(nd == nullptr)
        {
            ret.BST = true;
            ret.nmin = INT64_MAX;
            ret.nmax = INT64_MIN;
            return ret;
        }

        triad l = isaBST(nd->left);
        triad r = isaBST(nd->right);

        if(l.nmax < nd->val  &&  nd->val < r.nmin  && l.BST == true  &&  r.BST == true)
            ret.BST = true;
        else
            ret.BST = false;

        ret.nmin = min(l.nmin,(long)nd->val); // basically a hacky to handle leaf nodes, when nd->data needs to be returned
        ret.nmax = max(r.nmax, (long)nd->val); // else generally l.first and r.second represent the min and max values in a subtree

        return ret;
    }
    
    bool isValidBST(TreeNode* root) {
        
        return isaBST(root).BST;
    }
};