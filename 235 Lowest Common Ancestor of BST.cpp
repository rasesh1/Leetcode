/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int val1 = p->val;
        int val2 = q->val;
        
        bool cond = (root->val >= p->val && root->val <= q->val) || (root->val <= p->val && root->val >= q->val);
        
        while(!cond) {
            if(root->val > p->val && root->val > q->val)
                root = root->left;
            else
                root = root->right;
            
            cond = (root->val >= p->val && root->val <= q->val) || (root->val <= p->val && root->val >= q->val);
        }
        
        return root;
    }
};