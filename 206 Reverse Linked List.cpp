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
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* origHead = head;
        while(origHead->next != NULL) {
            ListNode* newHead = origHead->next;
            origHead->next = newHead->next;
            newHead->next = head;
            head = newHead;
        }
        return head;
    }
};