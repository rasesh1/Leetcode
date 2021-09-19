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
    bool isValidBST(TreeNode* root, long long int mini, long long int maxi) {
        if(root == NULL) return true;
        int val = root->val;
        
        if( !(val < maxi && val > mini) )    return false;
        return isValidBST(root->left, mini, val) && isValidBST(root->right, val, maxi);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        int val = root->val;
        
        return isValidBST(root->left, -100000000000, val) && isValidBST(root->right, val, 100000000000);
        
    }
};