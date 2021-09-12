/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Check if cycle is present
        while(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
            if(fast != NULL) fast = fast->next;
            else return NULL;
            
            if(slow == fast) break;
        }
        if(fast == NULL) return NULL;
        
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};