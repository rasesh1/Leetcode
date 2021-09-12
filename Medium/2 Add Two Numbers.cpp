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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        
        int carry = 0;
        while(curr1 != NULL || curr2 != NULL)   {
            int val1 = curr1 != NULL ? curr1->val : 0;
            int val2 = curr2 != NULL ? curr2->val : 0;
            
            int sum = val1 + val2 + carry;
            ListNode* newNode = new ListNode(0);
            newNode->val = sum%10;
            carry = sum/10;
            curr->next = newNode;
            curr = curr->next;
            
            if(curr1 != NULL) curr1 = curr1->next;
            if(curr2 != NULL) curr2 = curr2->next;
        }
        if(carry > 0)   {
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }
        
        return head->next;
    }
};