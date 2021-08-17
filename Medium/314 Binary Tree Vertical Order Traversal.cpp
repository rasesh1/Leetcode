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
    void verticalOrderUtil(map<int,vector<int>>& mp, TreeNode* root) {
        if(root == NULL) return;
        
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty())   {
            TreeNode* node = q.front().first;
            int row = q.front().second;
            
            q.pop();
            
            if(mp.find(row) == mp.end()) mp[row] = {};
        
            mp[row].push_back(node->val);
            
            if(node->left)  {
                q.push(make_pair(node->left,row-1));
            }
            
            if(node->right)  {
                q.push(make_pair(node->right,row+1));
            }
        }
        return;
    }
    
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        map<int,vector<int>> mp;
        
        verticalOrderUtil(mp, root);
        
        map<int,vector<int>>::iterator iter;
        for(iter=mp.begin(); iter!= mp.end(); ++iter)
            ans.push_back(iter->second);
        return ans;
    }
};