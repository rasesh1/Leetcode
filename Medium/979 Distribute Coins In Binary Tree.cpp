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
    int ans = 0;
    
    vector<int> distributeCoinsUtil(TreeNode* root) {
        if(root == NULL) return {0,0};
        
        vector<int> left = distributeCoinsUtil(root->left);
        vector<int> right = distributeCoinsUtil(root->right);
        
        int coins = root->val + left[0] + right[0];
        int numNodes = 1 + left[1] + right[1];
        
        ans = ans + abs(coins - numNodes);
        
        return {coins, numNodes};
    }
    
public:
    int distributeCoins(TreeNode* root) {
        if(root == NULL) return 0;
        
        distributeCoinsUtil(root);
        return ans;
    }
};