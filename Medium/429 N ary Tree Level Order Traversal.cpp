/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Point {
public:
    int level;
    Node* node;
    
    Point(int level, Node* node)    {
        this->level = level;
        this->node = node;
    }
};

class Solution {
private:
    vector<vector<int>> ans;
    
    void addToResult(vector<vector<int>>& ans, int level, Node* node)   {
        if(ans.size() <= level) ans.push_back({});
        
        ans[level].push_back(node->val);
        return;
    }
    
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return ans;
        
        queue<Point*> q;
        q.push(new Point(0, root));
        
        while(!q.empty())   {
            Point* top = q.front(); q.pop();
            addToResult(ans, top->level, top->node);
            
            vector<Node*> children = top->node->children;
            
            for(auto child : children)  {
                if(child != NULL)   {
                    q.push(new Point(top->level+1, child));
                }
            }
            
        }
        return ans;
    }
};