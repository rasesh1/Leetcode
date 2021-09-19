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
    unordered_map<int, int> mp;
    
    void pathSumUtil(TreeNode* root, int targetSum, int runningSum) {
        if(root == NULL)  return;
        
        runningSum = runningSum + root->val;
        int remain = runningSum - targetSum;
        
        if(mp.find(remain) != mp.end()) count = count + mp[remain];
        if(mp.find(runningSum) == mp.end()) mp[runningSum] = 0;
                
        mp[runningSum]++;
        pathSumUtil(root->left, targetSum, runningSum);
        pathSumUtil(root->right, targetSum, runningSum);
        mp[runningSum]--;
        
        runningSum = runningSum - root->val;
        return;
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        mp[0] = 1;
        pathSumUtil(root, targetSum, 0);
        
        return count;
    }
};