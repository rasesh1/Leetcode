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
class queueNode {    
private:
    TreeNode* node;
    long long int seq = 0;
    
    friend class Solution;
    
    queueNode(TreeNode* node, long long int seq)    {
        this->node = node;
        this->seq = seq;
    }
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<queueNode *> q;
        q.push(new queueNode(root,0));
        q.push(new queueNode(NULL,0));
        long long int maxDist = 0;
        long long int minSeq = -1;
        long long int maxSeq = -1;
        
        while(!q.empty())   {
            queueNode* top = q.front();
            q.pop();
            
            TreeNode* node = top->node;
            long long int seq = top->seq;
            
            if(node == NULL) {
                delete top;
                maxDist = max(maxDist, maxSeq+1);
                if(q.empty()) break;
                
                q.push(new queueNode(NULL,0));
                minSeq = -1;
                maxSeq = 0;
                continue;
            }
            
            if(minSeq < 0) minSeq = seq;
            maxSeq = seq-minSeq;
            
            if(node->left) q.push(new queueNode(node->left,2*seq-2*minSeq));
            if(node->right) q.push(new queueNode(node->right,2*seq+1-2*minSeq));
            
            delete top;
        }
        return maxDist;
    }
};