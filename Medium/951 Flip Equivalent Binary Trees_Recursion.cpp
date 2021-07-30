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
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;
        
        if(root1->val != root2->val) return false;
        
        if(!root1->left && !root2->left && !root2->right && !root1->right) return true;
        
        bool left = false;
        bool right = false;
        
        if(!root1->left)    {
            if(!root2->left)    {
            right = flipEquiv(root1->right, root2->right);
            return right;
            }
            else if(!root2->right)  {
                right = flipEquiv(root1->right, root2->left);
                return right;
            }
            else return false;
        }
        
        if(!root1->right)    {
            if(!root2->left)    {
                right = flipEquiv(root1->left, root2->right);
                return right;
            }
            else if(!root2->right)  {
                right = flipEquiv(root1->left, root2->left);
                return right;
            }
            else return false;
        }
        
        if(!root2->left || !root2->right) return false;
        
        if(root1->left->val == root2->left->val && root1->right->val == root2->right->val)    {
            left = flipEquiv(root1->left, root2->left);
            right = flipEquiv(root1->right, root2->right);
        }
        
        else if(root1->right->val == root2->left->val && root2->right->val == root1->left->val)    {
            left = flipEquiv(root1->right, root2->left);
            right = flipEquiv(root1->left, root2->right);
        }
        
        return left && right;
        
    }
};