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
    int height = 0;
    vector<int> ans;
    
    void TraverseSubtree(TreeNode* root, int steps) {
        if(root == NULL) return;
        
        if(steps == 1)  {
            ans.push_back(root->val);
            return;
        }
        
        TraverseSubtree(root->left, steps-1);
        TraverseSubtree(root->right, steps-1);
        return;
    }
    
    int distanceKUtil(TreeNode* root, TreeNode* target, int k, int level)    {
        if(root == NULL) return -1;
        if(root == target)  {
            height = level;
            TraverseSubtree(root, k+1);
            return k-1;
        }
        
        int left = distanceKUtil(root->left, target, k, level+1);
        int right = distanceKUtil(root->right, target, k, level+1);
        
        if(left == 0) ans.push_back(root->val);
        if(right == 0) ans.push_back(root->val);
        
        if(left > -1)  {
            // Traverse left steps in the other direction
            TraverseSubtree(root->right, left);
            return left-1;
        }
        else if(right > -1)    {
            // Traverse right steps in the other direction
            TraverseSubtree(root->left, right);
            return right-1;
        }
        return -1;
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        if(root == NULL) return {};
        
        distanceKUtil(root, target, k, 0);
        return ans;
    }
};