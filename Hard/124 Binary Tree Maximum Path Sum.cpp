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
    int maxSum = 0;
    int maxPathSumUtil(TreeNode* root)  {
        
        if(root == NULL) return 0;
        
        int left = maxPathSumUtil(root->left);
        int right = maxPathSumUtil(root->right);
        
        int val = root->val;
        
        if(left>0) val = left+val;
        if(right>0) val = right+val;
        
        if(val > maxSum) maxSum = val;
        return max(0,max(left,right)) + root->val;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        
        maxSum = root->val;
        int sumSoFar = 0;
        maxPathSumUtil(root);
        return maxSum;
    }
};