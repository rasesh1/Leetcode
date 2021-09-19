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
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> ancestors_p;
        
        Node* parent_p = p;
        while(parent_p != NULL) {
            ancestors_p.insert(parent_p);
            parent_p = parent_p->parent;
        }
        
        Node* parent_q = q;
        while(parent_q != NULL) {
            if(ancestors_p.find(parent_q) == ancestors_p.end()) {
                parent_q = parent_q->parent;
            }
            else return parent_q;
        }
        return NULL;
    }
};