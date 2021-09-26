/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
private:
    Node* prev;
    
    void treeToDoublyListUtil(Node* root)   {
        if(root == NULL) return;
        
        treeToDoublyListUtil(root->left);
        
        prev->right = root;
        root->left = prev;
        prev = root;
        
        treeToDoublyListUtil(root->right);
        return;
    }
    
public:
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return root;
        
        Node* fakeHead = new Node(-1);
        fakeHead->right = prev;
        prev = fakeHead;
        
        treeToDoublyListUtil(root);
        
        // Convert to circular
        Node* head = fakeHead->right;
        head->left = prev;
        prev->right = head;
        return head;
        
    }
};