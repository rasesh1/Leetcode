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
    vector<vector<int>> ans;
    
    void pathSumUtil(TreeNode* root, int target, vector<int>& path)    {
        if(root == NULL) return;
        
        int remain = target-root->val;
        vector<int> temp = path;
        temp.push_back(root->val);
        
        if(remain == 0 && (root->left == NULL && root->right == NULL) ) {
            ans.push_back(temp);
            return;
        }
        
        pathSumUtil(root->left, remain, temp);
        pathSumUtil(root->right, remain, temp);
        return;
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return ans;
        
        vector<int> curr;
        pathSumUtil(root, targetSum, curr);
        return ans;
    }
};