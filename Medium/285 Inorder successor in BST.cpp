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
private:
    TreeNode* successorInRightSubtree(TreeNode* root)   {
        while(root->left) root = root->left;
        return root;
    }
    
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == NULL) return NULL;
        
        if(p->right != NULL)
            return successorInRightSubtree(p->right);
        
        TreeNode* lastLeft = NULL;
        while(root != p)    {
            int val = root->val;
            if(val > p->val)    {
                lastLeft = root;
                root = root->left;
            }
            else root = root->right;
        }
        return lastLeft;
    }
};