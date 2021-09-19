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
    TreeNode* ancestor = NULL;
    
    int lowestCommonAncestorUtil(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return {};
        if(ancestor != NULL) return {};
        
        int score = 0;
        
        if(root == p)
            score++;
            
        if(root == q)
            score++;
        
        score = score + lowestCommonAncestorUtil(root->left, p, q);
        score = score + lowestCommonAncestorUtil(root->right, p, q);
        
        if(ancestor == NULL && score >= 2) {
            ancestor = root;
        }
        
        return score;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        
        lowestCommonAncestorUtil(root, p, q);
        return ancestor;
        
    }
};