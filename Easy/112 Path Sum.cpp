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
private:
    bool hasPathSumUtil(TreeNode* root, int target)  {
        if(root == NULL) return false;
        
        int val = root->val;
        int remain = target-val;
        
        if(remain == 0 && (root->left == NULL && root->right == NULL) ) return true;
        
        return hasPathSumUtil(root->left, remain) || hasPathSumUtil(root->right, remain);
    }
    
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        
        return hasPathSumUtil(root, targetSum);
    }
};