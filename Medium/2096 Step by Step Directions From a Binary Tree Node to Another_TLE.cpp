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
    int startValue, endValue;
    
    vector<int> getDirectionsUtil(TreeNode* root, string& srcpath, string& destPath)    {
        if(root == NULL) return {0,0};
        
        vector<int> leftSide = getDirectionsUtil(root->left, srcpath, destPath);
        vector<int> rightSide = getDirectionsUtil(root->right, srcpath, destPath);
        
        vector<int> res = {0,0};
        if(root->val == startValue) res[0] = 1;
        if(root->val == endValue) res[1] = 1;
        
        res[0] = res[0] || leftSide[0] || rightSide[0];
        res[1] = res[1] || leftSide[1] || rightSide[1];
                        
        if(leftSide[0] == 1 && leftSide[1] == 1) return res;
        else if(rightSide[0] == 1 && rightSide[1] == 1) return res;
        else if(leftSide[0] == 1 || rightSide[0] == 1) srcpath = "U" + srcpath;
        
        if(leftSide[1] == 1) destPath = "L" + destPath;
        else if(rightSide[1] == 1) destPath = "R" + destPath;
        
        return res;
    }
    
public:
    string getDirections(TreeNode* root, int startVal, int destVal) {
        if(root == NULL) return "";
        
        startValue = startVal;
        endValue = destVal;
        string srcPath = "";
        string destPath = "";
        
        getDirectionsUtil(root, srcPath, destPath);
        return srcPath + destPath;
    }
};