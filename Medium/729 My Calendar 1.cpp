typedef struct TreeNode2    {
    int val1;
    int val2;
    struct TreeNode2* left;
    struct TreeNode2* right;
} TreeNode2;

class MyCalendar {
private:
    TreeNode2* root = NULL;
    
    bool isOverlap(int s1, int e1, int s2, int e2)  {
        if(s1 >= e2 || s2 >= e1) return false;
        return true;
    }
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        TreeNode2 *node = new TreeNode2();
        node->val1 = start;
        node->val2 = end;
        node->left = NULL;
        node->right = NULL;
        
        if(root == NULL)    {
            root = node;
            return true;
        }
                
        if(isOverlap(start,end, root->val1, root->val2))
            return false;
        
        TreeNode2* root_temp = root;
        while(root_temp != NULL)   {
            
            bool left = true;
            if(start >= root_temp->val2)    {
                left = false;
            }
            
            if(root_temp->left) {
                if(isOverlap(start,end,root_temp->left->val1, root_temp->left->val2 ))
                    return false;
                else if(left) root_temp = root_temp->left;
            }
            else if(left)    {
                root_temp->left = node;
                return true;
            }
            
            if(root_temp->right) {
                if(isOverlap(start,end,root_temp->right->val1, root_temp->right->val2 ))
                    return false;
                else if(!left) root_temp = root_temp->right;
            }
            else if(!left)  {
                root_temp->right = node;
                return true;
            }
            
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */