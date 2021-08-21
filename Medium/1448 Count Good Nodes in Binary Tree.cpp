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
    void goodNodesUtil(TreeNode* root, int maxSoFar)    {
        if(root==NULL) return;
        
        int val = root->val;
        if(val >= maxSoFar) ans++;
        
        goodNodesUtil(root->left, max(root->val,maxSoFar) );
        goodNodesUtil(root->right, max(root->val,maxSoFar));
        return;
    }
    
public:
    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        ans++;
        
        goodNodesUtil(root->left, root->val);
        goodNodesUtil(root->right, root->val);
        return ans;
    }
};