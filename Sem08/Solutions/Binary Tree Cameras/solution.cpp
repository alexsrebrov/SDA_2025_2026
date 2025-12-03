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
    int buckets = 0;

    // DFS функцията връща:
    // 0 = неоцветен
    // 1 = има кофа
    // 2 = оцветен от дете
    int dfs(TreeNode* root) {
        if (!root) return 2;  // празните възли ги смятаме за оцветени

        int left = dfs(root->left);
        int right = dfs(root->right);

        // Ако някое дете е неоцветено, трябва да сложим кофа тук
        if (left == 0 || right == 0) {
            buckets++;
            return 1;
        }

        // Ако някое дете има кофа, този е оцветен
        if (left == 1 || right == 1) {
            return 2;
        }

        // Иначе остава неоцветен
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0)
            buckets++;
        return buckets;
    }
};
