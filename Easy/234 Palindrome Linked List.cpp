/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        
        ListNode* fakeHead = new ListNode(-1, head);
        stack<int> s;
        
        ListNode* fast = fakeHead;
        ListNode* slow = fakeHead;
        
        while(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
            if(fast == NULL) break;
            s.push(slow->val);
            fast = fast->next;
        }
        
        while(!s.empty() && slow != NULL)   {
            int val = slow->val;
            int top = s.top(); s.pop();
            
            if(val != top) return false;
            else slow = slow->next;
        }
        
        return true;
        
    }
};