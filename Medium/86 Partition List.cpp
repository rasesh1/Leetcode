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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* fakeHead = new ListNode(-1, head);
        
        ListNode* curr = head;
        ListNode* prev = fakeHead;
        ListNode* biggerHead = new ListNode(-1);
        ListNode* iter = biggerHead;
        
        while(curr != NULL) {
            int val = curr->val;
            ListNode* next = curr->next;
            if(val >= x)    {
                prev->next = curr->next;
                iter->next = curr;
                curr->next = NULL;
                iter = iter->next;
            }
            else prev = prev->next;
            curr = next;
        }
        prev->next = biggerHead->next;
        return fakeHead->next;
    }
};