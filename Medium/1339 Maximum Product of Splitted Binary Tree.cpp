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

typedef long long int lli;
class Solution {
private:
    long long int maxi=0;
    int sum = 0;
    
    void calcSum(TreeNode* root)    {
        if(root == NULL) return;
        
        sum = sum + root->val;
        calcSum(root->left);
        calcSum(root->right);
        return;
    }
    
    int maxProductUtil(TreeNode* root)  {
        if(root == NULL) return 0;
        
        lli left = maxProductUtil(root->left);
        lli right = maxProductUtil(root->right);
        
        long long int temp = max( (sum-left)*left, (sum-right)*right );
        maxi = max(maxi, temp);
        
        return left+right+root->val;
    }
    
public:
    int maxProduct(TreeNode* root) {
        if(root == NULL) return 0;
        
        calcSum(root);
        maxProductUtil(root);
        return maxi%1000000007;
    }
};