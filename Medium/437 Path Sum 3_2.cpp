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
    int count=0;
    
    void countTargetSums(vector<int>& curr, int targetSum)  {
        int n = curr.size();
        
        for(int j=0; j<n-1; j++)  {
            int diff = curr[n-1]-curr[j];
            if(diff == targetSum) count++;
        }
        return;
    }
    
    void pathSumUtil(TreeNode* root, int targetSum, vector<int>& curr) {
        if(root == NULL)  return;
        
        int n = curr.size();
        
        curr.push_back(curr[n-1] + root->val);
        
        countTargetSums(curr, targetSum);
        pathSumUtil(root->left, targetSum, curr);
        pathSumUtil(root->right, targetSum, curr);
        
        curr.pop_back();
        return;
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        
        vector<int> curr = {0};
        pathSumUtil(root, targetSum, curr);
        return count;
    }
};