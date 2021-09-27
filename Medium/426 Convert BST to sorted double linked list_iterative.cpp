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

public:
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return root;
        
        Node* fakeHead = new Node(-1);
        Node* prev = fakeHead;
        fakeHead->right = prev;
        
        stack<Node*> s;
        
        while(true) {
            while(root) {
                s.push(root);
                root = root->left;
            }
            if(s.empty()) break;

            root = s.top(); s.pop();

            root->left = prev;
            prev->right = root;
            prev = root;
            root = root->right;
        }
        
        // Making it circular
        Node* head = fakeHead->right;
        head->left = prev;
        prev->right = head;
        
        return head;
    }
};