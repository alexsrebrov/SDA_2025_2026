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
    bool isSymHelper(TreeNode* lhs, TreeNode* rhs)
    {
        if(!lhs && !rhs)
            return true;

        if(!lhs || !rhs)
            return false;
        
        if(lhs->val != rhs->val)
            return false;
        
        return isSymHelper(lhs->left, rhs->right) && isSymHelper(lhs->right, rhs->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
             
        return isSymHelper(root->left, root->right);
    }
};