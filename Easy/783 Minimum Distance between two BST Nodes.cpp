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
    int minDist = INT_MAX;
    void inorderTraversal(TreeNode* root, int *prev)   {
        if(root == NULL) return;
        
        inorderTraversal(root->left, prev);
        minDist = min(minDist, root->val- *prev);
        *prev = root->val;
        inorderTraversal(root->right, prev);
        return;
    }
    
public:
    int minDiffInBST(TreeNode* root) {
        if(root == NULL) return 0;
        
        int prev = INT_MIN+10000;
        inorderTraversal(root, &prev);
        return minDist;
    }
};