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
    vector<int> robUtil(TreeNode* root) {
        if(root == NULL) return {0,0};
        
        vector<int> left = robUtil(root->left);
        vector<int> right = robUtil(root->right);
        
        int includeRoot = root->val + left[0] + right[0];
        int notIncludeRoot = max(left[0],left[1]) + max(right[1], right[0]);
        
        return {notIncludeRoot, includeRoot};
    }
    
public:
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        
        vector<int> ans = robUtil(root);
        return max(ans[0], ans[1]);
    }
};