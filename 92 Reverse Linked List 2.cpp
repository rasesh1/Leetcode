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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL || left==right) return head;
        
        // Adding a dummy node
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        head = dummy;
        left++;
        right++;
        
        // Traverse to left node
        ListNode* prevLeft = head;
        int count=1;
        while(count < left-1) {
            prevLeft = prevLeft->next;
            count++;
        }
        
        ListNode* origLeft = prevLeft->next;
        ListNode* temp = origLeft;
        count++;
        while(count < right)    {
            ListNode* xxx = temp->next;
            temp->next = xxx->next;
            xxx->next = prevLeft->next;
            prevLeft->next = xxx;
            
            count++;
        }
        
        return head->next;
    }
};