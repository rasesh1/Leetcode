/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
private:
    Node* successorInLeftSubtree(Node* root)    {
        if(root == NULL) return NULL;
        while(root->left) root = root->left;
        return root;
    }
    
public:
    Node* inorderSuccessor(Node* node) {
        if(node == NULL) return NULL;
        
        if(node->right)
            return successorInLeftSubtree(node->right);
        
        Node* temp = node;
        while(temp->parent != NULL) {
            if(temp->parent != NULL && temp->parent->left == temp)
                return temp->parent;
            else temp = temp->parent;
        }
        return NULL;
    }
};